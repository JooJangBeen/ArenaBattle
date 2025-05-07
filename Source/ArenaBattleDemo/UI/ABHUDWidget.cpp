// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/ABHUDWidget.h"

#include "ABHpBarWidget.h"
#include "ABCharacterStatWidget.h"
#include "Interface/ABCharacterHUDInterface.h"

UABHUDWidget::UABHUDWidget(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
}

void UABHUDWidget::UpdateStat(const FABCharacterStat& BaseStat, const FABCharacterStat& ModifierStat)
{
	FABCharacterStat TotalStat = BaseStat + ModifierStat;

	//HpBar->SetMaxHp(TotalStat.MaxHp);
	HpBar->UpdateStat(BaseStat, ModifierStat);

	//캐릭터 스탯에 새로운 데이터 전달.
	CharacterStat->UpdateState(BaseStat, ModifierStat);
}

void UABHUDWidget::UpdateHpBar(float NewCurrentHp)
{
	HpBar->UpdateHpBar(NewCurrentHp);
}

void UABHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();

	//이름으로 검색해 HPBar 위젯 설정.
	HpBar = Cast<UABHpBarWidget>(GetWidgetFromName(TEXT("WidgetHpBar")));
	//제대로 로드 됐는지 확인.
	ensure(HpBar != nullptr);

	//이름으로 CharacterStat위젯 설정.
	CharacterStat = Cast<UABCharacterStatWidget>(GetWidgetFromName(TEXT("WidgetCharacterStat")));
	ensure(CharacterStat != nullptr);

	IABCharacterHUDInterface* HUDPawn = Cast<IABCharacterHUDInterface>(GetOwningPlayerPawn());
	if (HUDPawn)
	{
		HUDPawn->SetupHudWidget(this);
	}
	
}
