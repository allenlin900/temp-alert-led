# MSP430 溫度感測器小專案


## 專案簡介
利用 MSP430G2553 內建的 ADC 與溫度感測器，即時監控晶片內部溫度，當溫度超過初始的基準值時，控制 LED 進行閃爍，以示警示或狀態提示。



## 功能特色
- 使用 ADC 模組讀取內建溫度感測器資料

- 透過 TI 提供的校準資料進行溫度轉換與比對

- 若溫度超過設定基準，控制 LED 閃爍警示



