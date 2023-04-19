// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Piece.h"
#include "DiagonalBlock.generated.h"

/**
 * 
 */
UCLASS()
class TETRISUSFX01_API ADiagonalBlock : public APiece
{
	GENERATED_BODY()
	
public:
	ADiagonalBlock(); //Constructor

	void SpawnBlocks();
};
