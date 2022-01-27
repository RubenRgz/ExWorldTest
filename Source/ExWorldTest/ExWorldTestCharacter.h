// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ExWorldTest.h"
#include "ExWorldTestCharacter.generated.h"

UCLASS()
class EXWORLDTEST_API AExWorldTestCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AExWorldTestCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Called when shoot input is pressed
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnShootStart();

	// Called when the server ends shoot calculation
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnShootEnd();

	// Called when projectile actor overlaps an object
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnShootHits(AActor* AffectedActor);

	// Called when projectile actor is spawned
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnSpawnProjectile(FVector StartPoint, FVector EndPoint);

	// Called when OnShootEnd event is called to apply a specific effect
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnApplyEffect(FEffectData EffectInfo);

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Gameplay")
	EObjectType ObjectType;
};
