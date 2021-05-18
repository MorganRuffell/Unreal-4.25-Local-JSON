// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "SequencerDataAsset.h"

USequencerDataAsset::USequencerDataAsset()
{

}

TSharedPtr<FJsonObject> USequencerDataAsset::ToJson()
{
    TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();

    return jsonObject;
}

bool USequencerDataAsset::FromJson(FJsonObject& jsonObject)
{
    return true;
}
