// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DataAssets/JSON/JSONDataAssetBase.h"
#include "JSONValuesForAActor.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI) 
class UJSONValuesForAActor : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ACTIONRPG_API IJSONValuesForAActor
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	//
	virtual bool GetJSONDataAssetData(UJSONDataAssetBase DataAsset);
	
	virtual bool GetJSONDataAssetData();

	virtual bool GetJSONDataAssetData(UJSONDataAssetBase DataAsset) const;

	virtual bool GetJSONDataAssetData() const ;
};
 


