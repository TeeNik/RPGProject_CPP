#include "PlayerHealth.h"
#include "TimerManager.h"


UPlayerHealth::UPlayerHealth()
{
	PrimaryComponentTick.bCanEverTick = true;

	/*FTimerDelegate TimerDel;
	FTimerHandle TimerHandle;

	TimerDel.BindUFunction(this, FName("RegenMana"));
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDel, 0, true);*/

}

UPlayerHealth::~UPlayerHealth()
{
	GLog->Log("Destructor");
}

void UPlayerHealth::TakeDamage(float value)
{

}

bool UPlayerHealth::TakeMana(float value)
{
	if (Mana >= value) {
		Mana -= value;
		return true;
	}
	return false;
}


void UPlayerHealth::BeginPlay()
{
	Super::BeginPlay();
}

void UPlayerHealth::Dead()
{
	DestroyComponent();
	GLog->Log("Destroy");
}

void UPlayerHealth::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UPlayerHealth::RegenMana()
{
	Mana++;
	GLog->Log(FString::FromInt(Mana));
}

