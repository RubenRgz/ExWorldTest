// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ExWorldCooldownComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FActorComponentCooldownStartSignature, UExWorldCooldownComponent, OnCooldownStart, UExWorldCooldownComponent*, Component);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_TwoParams(FActorComponentCooldownUpdateSignature, UExWorldCooldownComponent, OnCooldownUpdate, UExWorldCooldownComponent*, Component, float, RemainingTime);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FActorComponentCooldownEndSignature, UExWorldCooldownComponent, OnCooldownEnd, UExWorldCooldownComponent*, Component);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EXWORLDTEST_API UExWorldCooldownComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UExWorldCooldownComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Initialize the current cooldown
	UFUNCTION(BlueprintCallable)
	void StartCooldown(AActor* Owner);

private:
	// Called to check if the current coldowns is active
	void CheckDuration();

	// Called to get the current time
	float GetWorldTime() const;

public:
	// Duration of the cooldown
	UPROPERTY(EditAnywhere, Category = "Gameplay")
	float Duration;

	// Notify when the current cooldown starts
	UPROPERTY(BlueprintAssignable, Category = "Components|Activation")
	FActorComponentCooldownStartSignature OnCooldownStart;

	// Returns the remaining time the active cooldown has
	UPROPERTY(BlueprintAssignable, Category = "Components|Activation")
	FActorComponentCooldownUpdateSignature OnCooldownUpdate;

	// Notify when the current cooldown ends
	UPROPERTY(BlueprintAssignable, Category = "Components|Activation")
	FActorComponentCooldownEndSignature OnCooldownEnd;

private:
	float StartTime;
	UWorld* WorldContext;
	bool CooldownActive;
};
