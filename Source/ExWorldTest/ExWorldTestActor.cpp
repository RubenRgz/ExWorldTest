// Fill out your copyright notice in the Description page of Project Settings.


#include "ExWorldTestActor.h"

// Sets default values
AExWorldTestActor::AExWorldTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AExWorldTestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AExWorldTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

