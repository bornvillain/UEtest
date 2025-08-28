// Fill out your copyright notice in the Description page of Project Settings.


#include "CppBaseActor.h"
#include "Engine/Engine.h"

// Sets default values
ACppBaseActor::ACppBaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);
}

// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay()
{
	Super::BeginPlay();
	InitialLocation=FVector(FMath::FRandRange(200.0f, 1000.0f), FMath::FRandRange(200.0f, 1000.0f), 500.0f);
}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACppBaseActor::ShowInformation() {

	GEngine->AddOnScreenDebugMessage(-1,10.0f,FColor::Black,PlayerName,true,FVector2D(2.0f,2.0f));

	UE_LOG(LogTemp, Display, TEXT("Display message"));
	UE_LOG(LogTemp, Warning, TEXT("Warning message"));
	UE_LOG(LogTemp, Error, TEXT("Error message"));

	UE_LOG(LogTemp, Display, TEXT("Instance name: %s"), *PlayerName);
	UE_LOG(LogTemp, Display, TEXT("EnemyNum: %d"), EnemyNum);
	UE_LOG(LogTemp, Display, TEXT("CurrentHealth: %f"), CurrentHealth);
	UE_LOG(LogTemp, Display, TEXT("IsAlive: %i"), isAlive);
}

void ACppBaseActor::SinMovement(){
	float z = Amplitude * FMath::Sin(Frequency * GetWorld()->GetTimeSeconds()) + InitialLocation.Z;
	FVector NewLocation = InitialLocation;
	NewLocation.Z = z;
	SetActorLocation(NewLocation);
}