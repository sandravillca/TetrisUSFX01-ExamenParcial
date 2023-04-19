// Fill out your copyright notice in the Description page of Project Settings.


#include "SixBlock.h"
#include <vector>

ASixBlock::ASixBlock()
{
    PrimaryActorTick.bCanEverTick = true;

    struct FConstructorStatics
    {
        ConstructorHelpers::FObjectFinderOptional<UMaterial> Color_7;
        
        FConstructorStatics()
            : Color_7(TEXT("Material'/Game/Mesh/Material_7.Material_7'"))            
        {
        }
    };
    static FConstructorStatics ConstructorStatics;
    Colors.Add(ConstructorStatics.Color_7.Get());    
}
void ASixBlock::SpawnBlocks()
{
    std::vector<std::pair<float, float>> Shapes =
    { {-20.0, 0.0}, {-10.0, 0.0}, {0.0, 0.0}, {-20.0, 10.0}, {-10.0,10.0}, {0.0,10.0} };            
        
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



