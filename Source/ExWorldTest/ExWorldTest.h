// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

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
