#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FToolBarBuilder;
class FMenuBuilder;

DECLARE_LOG_CATEGORY_EXTERN(LogModdingEx, Log, All);

class FModdingExModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	void OnPostWorldInit(UWorld* World, const UWorld::InitializationValues IVS);
	void OnOpenPluginSettings() const;
	void OnOpenBlueprintCreator() const;
	void OnOpenModCreator() const;
	FReply TryStartGame() const;
	void OnOpenGameFolder() const;
	void OnOpenRepository() const;


private:
	void RegisterMenus();

	TSharedPtr<FUICommandList> PluginCommands;

	// List of mods that can be build before starting the game + "None"
	TArray<TSharedPtr<FString>> StartBuildMods;
	TSharedPtr<FString> SelectedStartBuildMod;
};
