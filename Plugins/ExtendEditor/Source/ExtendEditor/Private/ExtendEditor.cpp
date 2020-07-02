// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "ExtendEditor.h"
#include "ExtendEditorStyle.h"
#include "ExtendEditorCommands.h"
#include "Misc/MessageDialog.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "LevelEditor.h"
#include "ContentBrowserModule.h"

static const FName ExtendEditorTabName("ExtendEditor");

#define LOCTEXT_NAMESPACE "FExtendEditorModule"

void FExtendEditorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FExtendEditorStyle::Initialize();
	FExtendEditorStyle::ReloadTextures();

	FExtendEditorCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FExtendEditorCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FExtendEditorModule::PluginButtonClicked),
		FCanExecuteAction());
		
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	
	{
		TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		MenuExtender->AddMenuExtension("WindowLayout", EExtensionHook::After, PluginCommands, FMenuExtensionDelegate::CreateRaw(this, &FExtendEditorModule::AddMenuExtension));

		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	}

	{
		TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
		ToolbarExtender->AddToolBarExtension("Settings", EExtensionHook::After, PluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &FExtendEditorModule::AddToolbarExtension));
		
		LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	}

	{
		TSharedPtr<FExtender> MenuBarExtender = MakeShareable(new FExtender());
		MenuBarExtender->AddMenuBarExtension("Help", EExtensionHook::After, PluginCommands, FMenuBarExtensionDelegate::CreateRaw(this, &FExtendEditorModule::AddMenuBarExtension));

		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuBarExtender);
	}

	{
		auto& MenuButtonArray = LevelEditorModule.GetAllLevelViewportContextMenuExtenders();
		MenuButtonArray.Add(FLevelEditorModule::FLevelViewportMenuExtender_SelectedActors::CreateRaw(this, &FExtendEditorModule::SelectedCurrentActors));

		LevelViewportMenuExtender_SelectedActor = MenuButtonArray.Last().GetHandle();
	}

	{
		FContentBrowserModule&  ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
		auto &MenuExtenderDelegates = ContentBrowserModule.GetAllPathViewContextMenuExtenders();

		MenuExtenderDelegates.Add(FContentBrowserMenuExtender_SelectedPaths::CreateRaw(this, &FExtendEditorModule::GetPathsFormEditor));
	}
}

void FExtendEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FExtendEditorStyle::Shutdown();

	FExtendEditorCommands::Unregister();
}

void FExtendEditorModule::PluginButtonClicked()
{
	// Put your "OnButtonClicked" stuff here
	FText DialogText = FText::Format(
							LOCTEXT("PluginButtonDialogText", "Add code to {0} in {1} to override this button's actions"),
							FText::FromString(TEXT("FExtendEditorModule::PluginButtonClicked()")),
							FText::FromString(TEXT("ExtendEditor.cpp"))
					   );
	FMessageDialog::Open(EAppMsgType::Ok, DialogText);
}

void FExtendEditorModule::AddMenuExtension(FMenuBuilder& Builder)
{
	Builder.BeginSection(TEXT("Helloworld"));
	{
		Builder.AddMenuEntry(FExtendEditorCommands::Get().PluginAction);
		Builder.AddMenuEntry(FExtendEditorCommands::Get().PluginAction);
		Builder.AddMenuEntry(FExtendEditorCommands::Get().PluginAction);
		Builder.AddMenuEntry(FExtendEditorCommands::Get().PluginAction);
	}
	Builder.EndSection();
}

void FExtendEditorModule::AddMenuBarExtension(FMenuBarBuilder &Builder)
{
	Builder.AddPullDownMenu(
		LOCTEXT("HELLO", "Hello"),
		LOCTEXT("I_AM_BUTTON", "I am button"),
		FNewMenuDelegate::CreateRaw(this, &FExtendEditorModule::PullDwonBar),
		"HelloW"
	);
}

void FExtendEditorModule::PullDwonBar(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FExtendEditorCommands::Get().PluginAction);
	Builder.AddMenuEntry(FExtendEditorCommands::Get().PluginAction);
	Builder.AddMenuSeparator();
	Builder.AddSubMenu(
		LOCTEXT("OK_ONE", "just a task"),
		LOCTEXT("OK_TWO", "just a task button"),
		FNewMenuDelegate::CreateRaw(this, &FExtendEditorModule::PullDwonSuBar)
	);

	Builder.AddMenuEntry(FExtendEditorCommands::Get().PluginAction);
}

void FExtendEditorModule::PullDwonSuBar(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FExtendEditorCommands::Get().PluginAction);
	Builder.AddMenuEntry(FExtendEditorCommands::Get().PluginAction);
	Builder.BeginSection(TEXT("Hall"));
	{
		Builder.AddMenuEntry(FExtendEditorCommands::Get().PluginAction);
		Builder.AddMenuEntry(FExtendEditorCommands::Get().PluginAction);
	}
	Builder.EndSection();

	Builder.AddWidget(
		SNew(SImage),
		LOCTEXT("IamgeTask", "just Iamge Task")
	);

	Builder.AddEditableText(
		LOCTEXT("OK_A", "just a Hello"),
		LOCTEXT("OK_B", "just a task Hello"),
		FSlateIcon(),
		LOCTEXT("TTT", "just a TTTTTT")
	);

	Builder.AddSearchWidget();

	Builder.AddWrapperSubMenu(
		LOCTEXT("III", "III III III"),
		LOCTEXT("RRR", "RRR RRR RRR RRR"),
		FOnGetContent::CreateStatic<TSharedPtr<FUICommandList>>(&FTaskABC::MakeWidget, PluginCommands),
		FSlateIcon()
	);
}

void FExtendEditorModule::EdtorPrint(FString MyString)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, MyString);
	}
}

TSharedRef<FExtender> FExtendEditorModule::SelectedCurrentActors(const TSharedRef<FUICommandList> MyUICommandList, const TArray<AActor*> AllActor)
{
	TSharedRef<FExtender> Extender = MakeShareable(new FExtender);

	EdtorPrint(FString::Printf(TEXT("Actor Number = %d"), AllActor.Num()));

	if (AllActor.Num() > 0)
	{

		FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
		TSharedRef<FUICommandList> LevelCommand = LevelEditorModule.GetGlobalLevelEditorActions();

		Extender->AddMenuExtension("ActorControl", EExtensionHook::After, LevelCommand, FMenuExtensionDelegate::CreateRaw(this, &FExtendEditorModule::AddSelectActorButton));
	}

	return Extender;
}

void FExtendEditorModule::AddSelectActorButton(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FExtendEditorCommands::Get().PluginAction);

	Builder.AddMenuSeparator();
	Builder.AddSubMenu(
		LOCTEXT("OK_ONE", "just a task"),
		LOCTEXT("OK_TWO", "just a task button"),
		FNewMenuDelegate::CreateRaw(this, &FExtendEditorModule::PullDwonSuBar)
	);
}

TSharedRef<FExtender> FExtendEditorModule::GetPathsFormEditor(const TArray<FString>& NewPaths)
{
	TSharedRef<FExtender> Extender = MakeShareable(new FExtender);

	EdtorPrint(FString::Printf(TEXT("Actor Number = %d"), NewPaths.Num()));

	if (NewPaths.Num() > 0)
	{

		//FContentBrowserModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
		//�˴���û�����ɣ�
		Extender->AddMenuExtension("NewFolder", EExtensionHook::After, PluginCommands, FMenuExtensionDelegate::CreateRaw(this, &FExtendEditorModule::AddSelectActorButton));
	}

	for (auto Tmp : NewPaths)
	{
		EdtorPrint(Tmp);
	}

	return Extender;
}

void FExtendEditorModule::AddToolbarExtension(FToolBarBuilder& Builder)
{
	//Builder.AddToolBarButton(FExtendEditorCommands::Get().PluginAction);

	Builder.BeginSection("HellWorldC");
	Builder.BeginBlockGroup();
	{
		//Builder.AddToolBarButton(
		//	FExtendEditorCommands::Get().PluginAction,
		//	NAME_None,
		//	TAttribute<FText>(),
		//	TAttribute<FText>(),
		//	TAttribute<FSlateIcon>(),
		//	TEXT("HellWorldCC")
		//);

		Builder.AddComboButton(
			FUIAction(),
			FOnGetContent::CreateStatic<TSharedPtr<FUICommandList>>(&FTaskABC::MakeWidget, PluginCommands),
			LOCTEXT("HHHH", "PHHHH"),
			LOCTEXT("CCCC", "I am C"),
			FSlateIcon()
		);
	}
	Builder.EndBlockGroup();
	Builder.EndSection();
}

TSharedRef<SWidget> FTaskABC::MakeWidget(TSharedPtr<class FUICommandList> PluginCommands)
{
	return SNew(SImage);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FExtendEditorModule, ExtendEditor)