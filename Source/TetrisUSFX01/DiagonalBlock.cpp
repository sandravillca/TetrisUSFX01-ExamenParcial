// Fill out your copyright notice in the Description page of Project Settings.


#include "DiagonalBlock.h"
#include <vector>

ADiagonalBlock::ADiagonalBlock()
{
    PrimaryActorTick.bCanEverTick = true;

    struct FConstructorStatics
    {
        ConstructorHelpers::FObjectFinderOptional<UMaterial> Color_8;

        FConstructorStatics()
            : Color_8(TEXT("Material'/Game/Mesh/Material_8.Material_8'"))
        {
        }
    };
    static FConstructorStatics ConstructorStatics;
    Colors.Add(ConstructorStatics.Color_8.Get());
}
void ADiagonalBlock::SpawnBlocks()
{
    std::vector<std::pair<float, float>> Shapes =
    { {-30.0, 0.0}, {-20.0, 0.0}, {-30.0, 10.0}, {-20.0, 10.0}, {-10.0,10.0}, {0.0,10.0}, {-10.0,20.0}, {0.0,20.0 } };

    //const std::pair<float, float>& YZs = Shapes[0];
    for (auto&& YZ : Shapes)
    {
        FRotator Rotation(0.0, 0.0, 0.0);
        ABlock* B = GetWorld()->SpawnActor<ABlock>(this->GetActorLocation(), Rotation);

        B->BlockMesh->SetMaterial(1, Colors[7]);

        Blocks.Add(B);
        B->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
        B->SetActorRelativeLocation(FVector(0.0, YZ.first, YZ.second));
    }
}

