// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "FirstInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UFirstInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ACTIONRPG_API IFirstInterface
{
	GENERATED_BODY()

	//virtual decleration
	//Allow us to give default functionality.
	virtual void ChocolateCake();

	//Pure virtual Decleration
	//Removes all default functionality we define that in subclasses.
	virtual void Cake() = 0;

	//You need to mark stuff that does not change values as const.


	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
};
