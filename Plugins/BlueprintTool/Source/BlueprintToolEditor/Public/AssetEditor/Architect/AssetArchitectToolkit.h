#pragma once
#include "Toolkits/AssetEditorToolkit.h"
#include "Misc/NotifyHook.h"

class UBlueprintData;
class FBlueprintToolEditorToolkit : public FAssetEditorToolkit, public FNotifyHook
{
	typedef FAssetEditorToolkit Super;

public:
	virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;

	void Initialize(UBlueprintData* InTextAsset, const EToolkitMode::Type InMode, const TSharedPtr<IToolkitHost>& InToolkitHost);

	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual FString GetWorldCentricTabPrefix() const override;
	virtual FLinearColor GetWorldCentricTabColorScale() const override;

private:
	TSharedRef<SDockTab> SpawnByPreviewTab(const FSpawnTabArgs& Args);
	TSharedRef<SDockTab> SpawnByContentBrowserTab(const FSpawnTabArgs& Args);
	TSharedRef<SDockTab> SpawnByBlueprintViewTab(const FSpawnTabArgs& Args);
	TSharedRef<SDockTab> SpawnByPaletteTab(const FSpawnTabArgs& Args);
	TSharedRef<SDockTab> SpawnByDetailsTab(const FSpawnTabArgs& Args);

	TSharedRef<SGraphEditor> CreateBPGraphEditor(UEdGraph* InGraph);

private:
	UBlueprintData* BlueprintData;									//����

private:
	TSharedPtr<IDetailsView> PropertyEditor;						//ϸ�����ʵ��
	TSharedPtr<class SBlueprintNodeListPalette> ActionPalette;		//��ͼ�б�
	TSharedPtr<class SGraphEditor> GraphEditor;						//��ͼ��
	TSharedPtr<class SBlueprintPreviewViewport> PreviewViewport;	//����ӿ�
};