// Fill out your copyright notice in the Description page of Project Settings.


#include "ExWorldCooldownComponent.h"
#include "GameFramework/GameStateBase.h"

// Sets default values for this component's properties
UExWorldCooldownComponent::UExWorldCooldownComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UExWorldCooldownComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
	CooldownActive = false;
}


// Called every frame
void UExWorldCooldownComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	CheckDuration();
}

void UExWorldCooldownComponent::StartCooldown(AActor* Owner)
{
	WorldContext = Owner->GetWorld();
	StartTime = GetWorldTime();
	CooldownActive = true;
	OnCooldownStart.Broadcast(this);
}

void UExWorldCooldownComponent::CheckDuration()
{
	if (CooldownActive)
	{
		float CurrentTime = GetWorldTime();
		float ElapsedTime = CurrentTime - StartTime;

		if (Duration > 0.f && (ElapsedTime) < Duration)
		{
			// Cooldown Active
			OnCooldownUpdate.Broadcast(this, Duration - ElapsedTime);
		}
		else
		{
			// Cooldown Inactive
			CooldownActive = false;
			OnCooldownEnd.Broadcast(this);
		}
	}
}

float UExWorldCooldownComponent::GetWorldTime() const
{
	AGameStateBase* GameState = WorldContext->GetGameState();
	if (GameState)
	{
		return GameState->GetServerWorldTimeSeconds();
	}

	return WorldContext->GetTimeSeconds();
}
