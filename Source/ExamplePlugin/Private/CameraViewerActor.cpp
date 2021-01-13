// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraViewerActor.h"

#include "Kismet/KismetMathLibrary.h"

// Sets default values
ACameraViewerActor::ACameraViewerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UStaticMeshComponent* RootComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Root CameraViewerActor"));

	RootComponent = RootComp;
}

// Called when the game starts or when spawned
void ACameraViewerActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACameraViewerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACameraViewerActor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	// Clear
	for (UCameraComponent* Camera : AllCameras)
	{
		Camera->DestroyComponent();
	}
	Transforms.Reset();
	AllCameras.Reset();

	// Load Camera
	for (int i = 0; i < CameraNumber; i++)
	{
		float CameraDegree = (360.0f / CameraNumber) * i;
		float CameraSin = FMath::Sin(CameraDegree);
		float CameraCos = FMath::Cos(CameraDegree);
		FVector CameraTranslation = FVector(CameraSin * Width, CameraCos * Width, Height);
		FRotator CameraRotation = UKismetMathLibrary::FindLookAtRotation(CameraTranslation, FVector::ZeroVector);
		FVector CameraScale = FVector::OneVector;
		FTransform CameraTransform = FTransform(CameraRotation, CameraTranslation, CameraScale);
		UCameraComponent* NewCameraComponent = CreateDefaultSubobject<UCameraComponent>(*FString("Camera " + (i + 1)));
		//NewCameraComponent->SetRelativeTransform(CameraTransform);
		//NewCameraComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
		// Add to lists
		AllCameras.Add(NewCameraComponent);
		Transforms.Add(CameraTransform);
	}
}

void ACameraViewerActor::ChangeCamera(APlayerController* Player, int CameraId)
{

}

void ACameraViewerActor::Next()
{

}

void ACameraViewerActor::Previous()
{

}
