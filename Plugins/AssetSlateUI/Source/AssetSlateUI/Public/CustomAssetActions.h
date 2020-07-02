#pragma once
#include "AssetTypeActions_Base.h"

class FCustomAssetActions: public FAssetTypeActions_Base
{
public:

	//���Ը��ǵ�ǰ��Դͼ��
	virtual TSharedPtr<class SWidget> GetThumbnailOverlay(const FAssetData& AssetData) const override;

	//�ɱ༭����Դ����
	virtual UClass* GetSupportedClass() const override;

	//��ʾͼ�����ɫ
	virtual FColor GetTypeColor() const override;

	//��˫����Դ��ʱ���ã�����򿪱༭��ʵ��
	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor = TSharedPtr<IToolkitHost>()) override;

	virtual FText GetName() const override;
	virtual uint32 GetCategories() override;
};