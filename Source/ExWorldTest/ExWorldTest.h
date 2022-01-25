// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ExWorldTest.generated.h"

/** Effects that can be applied when a projectile hits something. */
UENUM(BlueprintType)
enum class EEffectType : uint8 {
    ET_None                 UMETA(DisplayName = "None"),
    ET_Destroy              UMETA(DisplayName = "Destroy"),
    ET_SpawnParticles       UMETA(DisplayName = "SpawnParticles"),
    ET_AffectAttributes     UMETA(DisplayName = "AffectAttributes"),
};

/** Objects that can collied with the projectile. */
UENUM(BlueprintType)
enum class EObjectType : uint8 {
    OT_Static               UMETA(DisplayName = "Static"),
    OT_Pawn                 UMETA(DisplayName = "Pawn"),
    OT_Destructible         UMETA(DisplayName = "Destructible"),
};

/** Structure that defines a level up table entry */
USTRUCT(BlueprintType)
struct FEffectData : public FTableRowBase
{
    GENERATED_USTRUCT_BODY()

public:

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LevelUp)
    EObjectType CollidedTypeObject;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LevelUp)
    EEffectType EffectToApply;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LevelUp)
    bool IsProjectileDestructibleOnContact;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LevelUp)
    bool IsAoEDamage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LevelUp)
    TArray<EObjectType> AffectedTypes;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = LevelUp)
    int32 NumOfAffected;
};
