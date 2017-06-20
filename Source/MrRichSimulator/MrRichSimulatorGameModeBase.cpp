// Fill out your copyright notice in the Description page of Project Settings.

#include "MrRichSimulatorGameModeBase.h"
#include "Engine.h"
#include "MrRich.h"

AMrRichSimulatorGameModeBase::AMrRichSimulatorGameModeBase(const FObjectInitializer & ObjectInitializer) : Super(ObjectInitializer)
{
 ConstructorHelpers::FClassFinder<APawn>PlayerObject(TEXT("/Game/Blueprints/Character/MrRich_BP.MrRich_BP_C"));
 DefaultPawnClass = PlayerObject.Class;
}
