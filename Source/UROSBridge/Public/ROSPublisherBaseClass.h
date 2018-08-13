// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ROSBridgeSrvServer.h"
#include "ROSBridgePublisher.h"
#include "ROSBridgeSubscriber.h"
#include "ROSPublisherBaseClass.generated.h"

/**
 * This class is essentially an Interface. It is not meant to be instantiated.
 * An actuall interface could not be used, because Editor selection does not support
 * arrays of interfaces.
 */

UCLASS()
class UROSBRIDGE_API UROSPublisherBaseClass : public UObject
{
	GENERATED_BODY()

public:
	UROSPublisherBaseClass(){}
	~UROSPublisherBaseClass() {}


	/* 
	 * After call to this function the Arrays are expected to be set up correctly.
	 * If Namespace is not needed, just ignore it. It will always be provided.
	 */
	virtual void Init(FString DefaultNamespace)
	{
		UE_LOG(LogTemp, Error, TEXT("[%s]: This function schould be overriden by derived class. This class is meant to function like an Interface."), *FString(__FUNCTION__));
	};

	TArray<TSharedPtr<FROSBridgeSrvServer>> ServicesToPublish;
	TArray<TSharedPtr<FROSBridgePublisher>> PublisherToPublish;
	TArray<TSharedPtr<FROSBridgeSubscriber>> SubscriberToPublish;


};
