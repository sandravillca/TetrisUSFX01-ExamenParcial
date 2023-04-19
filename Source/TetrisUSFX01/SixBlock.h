// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Piece.h"
#include "SixBlock.generated.h"

/**
 * 
 */
UCLASS()
class TETRISUSFX01_API ASixBlock : public APiece
{
	GENERATED_BODY()
	
public:
	ASixBlock(); //Constructor

	void SpawnBlocks();
};
