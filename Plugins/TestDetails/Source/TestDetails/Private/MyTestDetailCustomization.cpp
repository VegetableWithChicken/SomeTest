#include "MyTestDetailCustomization.h"
#include "DetailCategoryBuilder.h"
#include "DetailLayoutBuilder.h"
#include "DetailWidgetRow.h"
#include "PropertyCustomizationHelpers.h"
#include "Widgets/Images/SImage.h"

#define LOCTEXT_NAMESPACE "MyTestDetailCustomization"

void FMyTestDetailCustomization::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	IDetailCategoryBuilder& DetailCategoryBuilderInstance = DetailBuilder.EditCategory(TEXT("CustomizeDetails"));
	TSharedPtr<IPropertyHandle> HelloI = DetailBuilder.GetProperty("HelloI");//获取这个变量
	DetailBuilder.AddPropertyToCategory(HelloI);//在分类中也可以看到
	DetailCategoryBuilderInstance
		.AddCustomRow(LOCTEXT("MMMM", "Hello Wolrd"))
		.WholeRowContent()
		[
			//SNew(STextBlock)
			//.Text(LOCTEXT("TTTT", "I am World"))
			SNew(SHorizontalBox)

			+ SHorizontalBox::Slot()
			[
				SNew(SProperty, HelloI)//类似StructVariableDetail.h可以自定义变量，但是如果只想修改一个变量
				.CustomWidget()
				[
					SNew(SImage)
				]
			]

			+ SHorizontalBox::Slot()
			[
				SNew(SProperty, DetailBuilder.GetProperty("HelloF"))
			]
		];
}

TSharedRef< IDetailCustomization > FMyTestDetailCustomization::MakeInstance()
{
	return MakeShareable(new FMyTestDetailCustomization);
}

#undef  LOCTEXT_NAMESPACE