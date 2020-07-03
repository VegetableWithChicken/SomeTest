#pragma once

#include "CoreMinimal.h"
#include "IPropertyTypeCustomization.h"

class FStructVariableDetail : public IPropertyTypeCustomization
{
public:

	/*
	*�����Եı��⣨��ʾ���Ե���ϸ��Ϣ����е��У�ʱ����
	*�������δ����κ����ݣ��򲻻���ʾ���⡣
	*@param PropertyHandle �����Զ�������Ծ��
	*@param HeaderRow �������С��������
	*@param CustomizationUtils �Զ���ʵ�ó���
	*/
	virtual void CustomizeHeader(TSharedRef<IPropertyHandle> PropertyHandle, FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& CustomizationUtils)override;
	
	/*
	*��Ӧ�Զ������Ե��Ӽ�����Ӷ������ʱ����
	*@param PropertyHandle �����Զ�������Ծ��
	*@param HeaderRow �������С��������
	*@param CustomizationUtils �Զ���ʵ�ó���
	*/
	virtual void CustomizeChildren(TSharedRef<IPropertyHandle> PropertyHandle, IDetailChildrenBuilder& ChildBuilder, IPropertyTypeCustomizationUtils& CustomizationUtils) override;

	//ʵ����
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();

	void OnPropertyTextCommited(const FText& InText, ETextCommit::Type InCommitType) const;
private:

	TSharedPtr<IPropertyHandle> PropertyText;

	TSharedPtr<class SEditableTextBox> EditableTextBox;
};