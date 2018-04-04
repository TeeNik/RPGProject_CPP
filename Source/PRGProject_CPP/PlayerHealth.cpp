#include "PlayerHealth.h"
#include "TimerManager.h"


UPlayerHealth::UPlayerHealth()
{
	PrimaryComponentTick.bCanEverTick = true;

	

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

	SetupTimer(FName("RegenMana"));
	SetupTimer(FName("RegenHealth"));
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
	if (Mana == MaxMana) return;
	Mana++;
	if (Mana > MaxMana) Mana = MaxMana;
}

void UPlayerHealth::RegenHealth()
{
	if (Health == MaxHealth) return;
	Health++;
	if (Health > MaxHealth) Health = MaxHealth;
}

void UPlayerHealth::SetupTimer(FName name)
{
	FTimerDelegate TimerDel;
	FTimerHandle TimerHandle;
	TimerDel.BindUFunction(this, FName(name));
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, TimerDel, 1, true);
}

