// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetActor.h"
#include <Net/UnrealNetwork.h>

ATargetActor::ATargetActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;
}

void ATargetActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ATargetActor, bBooleanValue);
}

void ATargetActor::ToogleBool()
{
	if (HasAuthority())
	{
		bBooleanValue = !bBooleanValue;
		OnRep_OnValueChange();
	}
}

void ATargetActor::OnRep_OnValueChange()
{
	if (OnBooleanValueChange.IsBound())
	{
		OnBooleanValueChange.Execute(bBooleanValue);
	}
}