
#pragma once

#include "CoreMinimal.h"
#include "IDetailCustomization.h"

class FMyTestDetailCustomization : public IDetailCustomization
{
public:

	//ӳ�䵽���������
	virtual void CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)override;

	//ʵ����
	static TSharedRef< IDetailCustomization > MakeInstance();
};