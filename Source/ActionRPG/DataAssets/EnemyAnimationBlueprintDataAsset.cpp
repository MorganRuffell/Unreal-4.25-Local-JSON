// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "EnemyAnimationBlueprintDataAsset.h"

UEnemyAnimationBlueprintDataAsset::UEnemyAnimationBlueprintDataAsset()
{

}

TSharedPtr<FJsonObject> UEnemyAnimationBlueprintDataAsset::ToJson()
{
    TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();

    jsonObject->SetNumberField("AnimationIndexDiceRoll", AnimationIndexDiceRoll);

    return jsonObject;
}

bool UEnemyAnimationBlueprintDataAsset::FromJson(FJsonObject& jsonObject)
{
    AnimationIndexDiceRoll = jsonObject.GetIntegerField("AnimationIndexDiceRoll");

    return true;
}
