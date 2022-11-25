#define LOG_LEVEL_LOCAL ESP_LOG_VERBOSE
#include "esp_log.h"
#define LOG_TAG "BLINK"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"


extern "C" void app_main(void)
{
    gpio_pad_select_gpio(GPIO_NUM_2);
    ESP_ERROR_CHECK(gpio_set_direction(GPIO_NUM_2,GPIO_MODE_OUTPUT)); 
    while (true)
    {
        ESP_LOGI(LOG_TAG, "LED ON");
        ESP_ERROR_CHECK(gpio_set_level(GPIO_NUM_2,1));
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        ESP_LOGI(LOG_TAG, "LED OFF");
        ESP_ERROR_CHECK(gpio_set_level(GPIO_NUM_2,0));
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    
}