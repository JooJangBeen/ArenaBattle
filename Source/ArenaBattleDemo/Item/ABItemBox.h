// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ABItemBox.generated.h"

UCLASS()
class ARENABATTLEDEMO_API AABItemBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AABItemBox();

protected:
	//박스 컴포넌트의 오버랩 델리게이트에 등록할 함수.
	//OnComponentBeginOverlap 델리게이트는 다이나믹으로 지정되어 있기대문에
	//UFUNCTION() 매크로를 지정해야 한다.
	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

	//파티클 재생 종료 시 발행되는 델리게이트에 등록 할 함수.
	UFUNCTION()
	void OnEffectFinished(class UParticleSystemComponent* PSystem );

protected:
	//액터의 충돌을 담당할 박스 컴포넌트.
	UPROPERTY(VisibleAnywhere, Category = Box)
	TObjectPtr<class UBoxComponent> TriggerBox;

	//아이템 박스를 보여줄 메시 컴포넌트.
	UPROPERTY(VisibleAnywhere, Category = Box)
	TObjectPtr<class UStaticMeshComponent> Mesh;

	//박스와 상호작용 했을때 보여줄 파티클 효과 컴포넌트.(나이아가라 X)
	UPROPERTY(VisibleAnywhere, Category = Box)
	TObjectPtr<class UParticleSystemComponent> Effect;

	//아이템 정보.
	UPROPERTY(EditAnywhere, Category = Item)
	TObjectPtr<class UABItemData> Item;
	
};
