Scriptname ZEDSBESetProneState extends ActiveMagicEffect  

import DynamicCollisionAdjustment_Prone

Actor Property PlayerRef  Auto  
GlobalVariable Property CanGetUp  Auto 

Event OnEffectStart(Actor akTarget, Actor akCaster)
  SetProneState(true, PlayerRef.isSneaking())
  RegisterforSingleUpdate(0.5)
endEvent

Event OnEffectFinish(Actor akTarget, Actor akCaster)
  SetProneState(false, PlayerRef.isSneaking())
endEvent

Event OnUpdate()
  if (CanPlayerGetUp())
    CanGetUp.SetValueInt(1)
  Else
    CanGetUp.SetValueInt(0)
  EndIf
  RegisterforSingleUpdate(0.5)
EndEvent 
