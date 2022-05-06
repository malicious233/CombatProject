#include "FGCamera.h"
#include "Camera/CameraComponent.h"

AFGCamera::AFGCamera()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(Root);
}

void AFGCamera::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* Controller = GetWorld()->GetFirstPlayerController();
	Controller->SetViewTarget(this);
}

void AFGCamera::Tick(float DeltaTime)
{
}
