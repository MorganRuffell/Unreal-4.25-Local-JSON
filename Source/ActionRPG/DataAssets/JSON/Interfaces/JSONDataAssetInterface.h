// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "JSONDataAssetInterface.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UJSONDataAssetInterface : public UInterface
{
	GENERATED_BODY()
};


class ACTIONRPG_API IJSONDataAssetInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.

public:

	virtual TSharedPtr<FJsonObject> ToJson() { return nullptr; }

	virtual bool FromJson(FJsonObject& jsonObject) { return false; }

};



