// Fill out your copyright notice in the Description page of Project Settings.


#include "FacePlayerActor.h"

#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFacePlayerActor::AFacePlayerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UStaticMeshComponent * Comp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("The Observer"));

	StaticMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'")).Object;

	Comp->SetStaticMesh(StaticMesh);

	RootComponent = Comp;
}

void AFacePlayerActor::OnConstruction(const FTransform& Transform)
{
	UStaticMeshComponent* Comp = Cast<UStaticMeshComponent>(RootComponent);
	Comp->SetStaticMesh(StaticMesh);
}

// Called when the game starts or when spawned
void AFacePlayerActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFacePlayerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (USceneComponent* RootComp = GetRootComponent()) {
		if (APawn* LocalPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0)) {
			RootComp->SetWorldRotation((LocalPawn->GetActorLocation() - RootComp->GetComponentLocation()).GetSafeNormal().Rotation());
		}
	}
}

