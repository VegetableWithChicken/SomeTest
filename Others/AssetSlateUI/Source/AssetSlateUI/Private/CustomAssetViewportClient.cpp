#include "CustomAssetViewportClient.h"
#include "AssetEditorModeManager.h"
#include "ProceduralMeshComponent.h"

FCustomAssetViewportClient::FCustomAssetViewportClient(FPreviewScene& InPreviewScene, UCustomAsset* InCustomAsset,const TWeakPtr<class SEditorViewport> &InEdiotrViewprtWdget /*= nullptr*/)
	:FEditorViewportClient(NULL, &InPreviewScene, InEdiotrViewprtWdget)
	, CustomAsset(InCustomAsset)
{
	((FAssetEditorModeManager*)ModeTools)->SetPreviewScene(PreviewScene);

	DrawHelper.bDrawGrid = true;
	DrawHelper.bDrawPivot = true;

	SetRealtime(true);

	SetViewMode(VMI_Lit);

	SetViewLocation(FVector(500, 300, 500));

	CreateMeshLOD();
	
	OnPropertyChanged();
}

void FCustomAssetViewportClient::Tick(float DeltaSeconds)
{
	FEditorViewportClient::Tick(DeltaSeconds);

	//������
	if (CustomAsset)
	{
		if (CustomAsset->IsModify())
		{
			OnPropertyChanged();
		}
		else
		{
			for (int32 LOD = 0; LOD < CustomAsset->MeshData.Num(); LOD++)
			{
				for (int32 Section = 0 ; Section < CustomAsset->MeshData[LOD].MeshLOD.Num(); Section++)
				{
					if (ProceduralMesh.IsValidIndex(LOD))
					{
						TArray<FColor> VertexColors;
						ProceduralMesh[LOD]->UpdateMeshSection(
							Section,
							CustomAsset->MeshData[LOD].MeshLOD[Section].Vertices,
							CustomAsset->MeshData[LOD].MeshLOD[Section].Normals,
							CustomAsset->MeshData[LOD].MeshLOD[Section].UV0,
							VertexColors,
							CustomAsset->MeshData[LOD].MeshLOD[Section].Tangents);
					}
					else
					{
						OnPropertyChanged();
					}
				}
			}
		}
	}

	PreviewScene->GetWorld()->Tick(LEVELTICK_All, DeltaSeconds);
}

void FCustomAssetViewportClient::OnPropertyChanged()
{
	if (CustomAsset)
	{
		for (int32 LOD = 0; LOD < CustomAsset->MeshData.Num(); LOD++)
		{
			for (int32 Section = 0; Section < CustomAsset->MeshData[LOD].MeshLOD.Num(); Section++)
			{
				if (ProceduralMesh.IsValidIndex(LOD))
				{
					TArray<FColor> VertexColors;
					ProceduralMesh[LOD]->CreateMeshSection(
						Section,
						CustomAsset->MeshData[LOD].MeshLOD[Section].Vertices,
						CustomAsset->MeshData[LOD].MeshLOD[Section].Triangles,
						CustomAsset->MeshData[LOD].MeshLOD[Section].Normals,
						CustomAsset->MeshData[LOD].MeshLOD[Section].UV0,
						VertexColors,
						CustomAsset->MeshData[LOD].MeshLOD[Section].Tangents,
						false);

					//�����л�Ŀǰֻ�ܼ���һ�����ʣ���Ϊ���ʻ�û����ȫ׼����
					//���Կ��ǰ������ ��CustomAsset->EndModifyMaterial();�� ע�͵��������������⡣
					//�����ͬ���ʸ�ֵ��UE4 ProceduralMesh ���ڲ���������жϵģ����赣�� �ڲ�����
					//�� if (OverrideMaterials.IsValidIndex(ElementIndex) && (OverrideMaterials[ElementIndex] == Material))��
					//�� ��if (CustomAsset->IsModifyMaterial())�� ֻ��Ϊ����ʾ ��virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;��
					if (CustomAsset->IsModifyMaterial())
					{
						for (int32 MaterNumber = 0; MaterNumber < ProceduralMesh[LOD]->GetNumMaterials(); MaterNumber++)
						{
							if (CustomAsset->MaterialInterface.IsValidIndex(MaterNumber))
							{
								ProceduralMesh[LOD]->SetMaterial(MaterNumber, CustomAsset->MaterialInterface[MaterNumber]);
							}
						}

						CustomAsset->EndModifyMaterial();
					}
				}
				else
				{
					if (CreateMeshLOD((LOD + 1) - ProceduralMesh.Num()))
					{
						TArray<FColor> VertexColors;
						ProceduralMesh[LOD]->CreateMeshSection(
							Section,
							CustomAsset->MeshData[LOD].MeshLOD[Section].Vertices,
							CustomAsset->MeshData[LOD].MeshLOD[Section].Triangles,
							CustomAsset->MeshData[LOD].MeshLOD[Section].Normals,
							CustomAsset->MeshData[LOD].MeshLOD[Section].UV0,
							VertexColors,
							CustomAsset->MeshData[LOD].MeshLOD[Section].Tangents,
							false);

						//�����л�Ŀǰֻ�ܼ���һ�����ʣ���Ϊ���ʻ�û����ȫ׼����
						//���Կ��ǰ������ ��CustomAsset->EndModifyMaterial();�� ע�͵��������������⡣
						//�����ͬ���ʸ�ֵ��UE4 ProceduralMesh ���ڲ���������жϵģ����赣�� �ڲ�����
						//�� if (OverrideMaterials.IsValidIndex(ElementIndex) && (OverrideMaterials[ElementIndex] == Material))��
						//�� ��if (CustomAsset->IsModifyMaterial())�� ֻ��Ϊ����ʾ ��virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;��
						if (CustomAsset->IsModifyMaterial())
						{
							for (int32 MaterNumber = 0; MaterNumber < ProceduralMesh[LOD]->GetNumMaterials(); MaterNumber++)
							{
								if (CustomAsset->MaterialInterface.IsValidIndex(MaterNumber))
								{
									ProceduralMesh[LOD]->SetMaterial(MaterNumber, CustomAsset->MaterialInterface[MaterNumber]);
								}
							}

							CustomAsset->EndModifyMaterial();
						}	
					}
				}
			}
		}
	}
}

bool FCustomAssetViewportClient::CreateMeshLOD(int32 LODNumber)
{
	bool bCreateMeshLOD = false;

	for (int32 i = 0 ; i < LODNumber ; i++)
	{
		UProceduralMeshComponent *ProceduralMeshComponent = NewObject<UProceduralMeshComponent>(PreviewScene->GetWorld(), TEXT("PreviewMesh"));

		if (ProceduralMeshComponent)
		{
			PreviewScene->AddComponent(ProceduralMeshComponent, FTransform::Identity);
			ProceduralMesh.Add(ProceduralMeshComponent);
			bCreateMeshLOD = true;
		}	
	}

	return bCreateMeshLOD;
}

