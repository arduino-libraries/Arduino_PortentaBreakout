/*
  portentaBreakoutAnalog.h 
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2018-2019 Arduino SA

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA
*/

namespace BreakoutPWM {


class HRTIMPWMClass {
public:
    HRTIMPWMClass() {
        GPIO_InitTypeDef   GPIO_InitStruct;

        // Enables peripherals and GPIO Clocks HRTIM1 Peripheral clock enable
        __HAL_RCC_HRTIM1_CLK_ENABLE();

        // Enable GPIO Channels Clock
        __HAL_RCC_GPIOG_CLK_ENABLE();

        // Configure HRTIMA TIMA TA1/A2, TIMB TB1/2, TIMC TC1/2, TIMD TD1/2 and TIME TE1.2
        // channels as alternate function mode

        GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
        GPIO_InitStruct.Pull = GPIO_PULLUP;
        GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
        GPIO_InitStruct.Alternate = GPIO_AF2_HRTIM1;
        GPIO_InitStruct.Pin = GPIO_PIN_7;
        HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);

        // Configure the HRTIM peripheral
        // Initialize the HRTIM structure
        HrtimHandle.Instance = HRTIM1;
        HrtimHandle.Init.HRTIMInterruptResquests = HRTIM_IT_NONE;
        HrtimHandle.Init.SyncOptions = HRTIM_SYNCOPTION_NONE;

        HAL_HRTIM_Init(&HrtimHandle);
#if 1
        // Configure the HRTIM TIME PWM channels 2
        sConfig_time_base.Mode = HRTIM_MODE_CONTINUOUS;
        sConfig_time_base.Period = 0xFFFD;
        sConfig_time_base.PrescalerRatio = HRTIM_PRESCALERRATIO_DIV4;
        sConfig_time_base.RepetitionCounter = 0;

        HAL_HRTIM_TimeBaseConfig(&HrtimHandle, HRTIM_TIMERINDEX_TIMER_E, &sConfig_time_base);

        sConfig_timerE.DMARequests = HRTIM_TIM_DMA_NONE;
        sConfig_timerE.HalfModeEnable = HRTIM_HALFMODE_DISABLED;
        sConfig_timerE.StartOnSync = HRTIM_SYNCSTART_DISABLED;
        sConfig_timerE.ResetOnSync = HRTIM_SYNCRESET_DISABLED;
        sConfig_timerE.DACSynchro = HRTIM_DACSYNC_NONE;
        sConfig_timerE.PreloadEnable = HRTIM_PRELOAD_ENABLED;
        sConfig_timerE.UpdateGating = HRTIM_UPDATEGATING_INDEPENDENT;
        sConfig_timerE.BurstMode = HRTIM_TIMERBURSTMODE_MAINTAINCLOCK;
        sConfig_timerE.RepetitionUpdate = HRTIM_UPDATEONREPETITION_ENABLED;
        sConfig_timerE.ResetUpdate = HRTIM_TIMUPDATEONRESET_DISABLED;
        sConfig_timerE.InterruptRequests = HRTIM_TIM_IT_NONE;
        sConfig_timerE.PushPull = HRTIM_TIMPUSHPULLMODE_DISABLED;
        sConfig_timerE.FaultEnable = HRTIM_TIMFAULTENABLE_NONE;
        sConfig_timerE.FaultLock = HRTIM_TIMFAULTLOCK_READWRITE;
        sConfig_timerE.DeadTimeInsertion = HRTIM_TIMDEADTIMEINSERTION_DISABLED;
        sConfig_timerE.DelayedProtectionMode = HRTIM_TIMER_D_E_DELAYEDPROTECTION_DISABLED;
        sConfig_timerE.UpdateTrigger= HRTIM_TIMUPDATETRIGGER_NONE;
        sConfig_timerE.ResetTrigger = HRTIM_TIMRESETTRIGGER_NONE;

        HAL_HRTIM_WaveformTimerConfig(&HrtimHandle, HRTIM_TIMERINDEX_TIMER_E,&sConfig_timerE);

        sConfig_compare.AutoDelayedMode = HRTIM_AUTODELAYEDMODE_REGULAR;
        sConfig_compare.AutoDelayedTimeout = 0;
        sConfig_compare.CompareValue = 0x7FFE;

        HAL_HRTIM_WaveformCompareConfig(&HrtimHandle, HRTIM_TIMERINDEX_TIMER_E, HRTIM_COMPAREUNIT_2, &sConfig_compare);

        sConfig_output_config.Polarity = HRTIM_OUTPUTPOLARITY_LOW;
        sConfig_output_config.SetSource = HRTIM_OUTPUTRESET_TIMCMP2;
        sConfig_output_config.ResetSource = HRTIM_OUTPUTSET_TIMPER;
        sConfig_output_config.IdleMode = HRTIM_OUTPUTIDLEMODE_NONE;
        sConfig_output_config.IdleLevel = HRTIM_OUTPUTIDLELEVEL_INACTIVE;
        sConfig_output_config.FaultLevel = HRTIM_OUTPUTFAULTLEVEL_NONE;
        sConfig_output_config.ChopperModeEnable = HRTIM_OUTPUTCHOPPERMODE_DISABLED;
        sConfig_output_config.BurstModeEntryDelayed = HRTIM_OUTPUTBURSTMODEENTRY_REGULAR;
        sConfig_output_config.ResetSource = HRTIM_OUTPUTRESET_TIMPER;
        sConfig_output_config.SetSource = HRTIM_OUTPUTSET_TIMCMP2;

        HAL_HRTIM_WaveformOutputConfig(&HrtimHandle, HRTIM_TIMERINDEX_TIMER_E, HRTIM_OUTPUT_TE2, &sConfig_output_config);

        // Start PWM signals generation
        if (HAL_HRTIM_WaveformOutputStart(&HrtimHandle, HRTIM_OUTPUT_TE2) != HAL_OK)
        {
            // PWM Generation Error
        }

        // Start HRTIM counter
        if (HAL_HRTIM_WaveformCounterStart(&HrtimHandle, HRTIM_TIMERID_TIMER_E) != HAL_OK)
        {
            // PWM Generation Error
        }
#else
        /*##-6- Configure the HRTIM TIME PWM channels 1 #############################################*/
        sConfig_time_base.Mode = HRTIM_MODE_CONTINUOUS;
        sConfig_time_base.Period = 100;
        sConfig_time_base.PrescalerRatio = HRTIM_PRESCALERRATIO_DIV4;
        sConfig_time_base.RepetitionCounter = 0;

        HAL_HRTIM_TimeBaseConfig(&HrtimHandle, HRTIM_TIMERINDEX_TIMER_E, &sConfig_time_base);

        sConfig_Channel.Polarity = HRTIM_OUTPUTPOLARITY_LOW;
        sConfig_Channel.IdleLevel = HRTIM_OUTPUTIDLELEVEL_INACTIVE;
        sConfig_Channel.Pulse = 63;

        HAL_HRTIM_SimplePWMChannelConfig(&HrtimHandle, HRTIM_TIMERINDEX_TIMER_E, HRTIM_OUTPUT_TE1, &sConfig_Channel);

        HAL_HRTIM_SimplePWMStart(&HrtimHandle, HRTIM_TIMERINDEX_TIMER_E, HRTIM_OUTPUT_TE2);
#endif
    }

    ~HRTIMPWMClass(){}

    void period_us(int period) {
        sConfig_time_base.Mode = HRTIM_MODE_CONTINUOUS;
        sConfig_time_base.Period = period * 50;
        sConfig_time_base.PrescalerRatio = HRTIM_PRESCALERRATIO_DIV4;
        sConfig_time_base.RepetitionCounter = 0;

        HAL_HRTIM_TimeBaseConfig(&HrtimHandle, HRTIM_TIMERINDEX_TIMER_E, &sConfig_time_base);
    }

    bool write(float pulse) {
        if (pulse > 100) {
            pulse = 100;
        }
        sConfig_compare.CompareValue = (sConfig_time_base.Period * pulse);
        if (HAL_HRTIM_WaveformCompareConfig(&HrtimHandle, HRTIM_TIMERINDEX_TIMER_E, HRTIM_COMPAREUNIT_2, &sConfig_compare) != HAL_OK)
        {
            return false;
        }
        return true;
    }

    bool stop() {
        if (HAL_HRTIM_SimplePWMStop(&HrtimHandle, HRTIM_TIMERINDEX_TIMER_E, HRTIM_OUTPUT_TE2) != HAL_OK)
        {
            return false;
        }
        return true;
    }

private:
    HRTIM_HandleTypeDef HrtimHandle;

    HRTIM_TimeBaseCfgTypeDef sConfig_time_base;
    HRTIM_TimerCfgTypeDef               sConfig_timerE;
    HRTIM_OutputCfgTypeDef              sConfig_output_config;
    HRTIM_CompareCfgTypeDef             sConfig_compare;
    HRTIM_SimplePWMChannelCfgTypeDef    sConfig_Channel;
};


void analogWrite(pin_size_t pin, int value);
void analogWriteResolution(int bits);

}

