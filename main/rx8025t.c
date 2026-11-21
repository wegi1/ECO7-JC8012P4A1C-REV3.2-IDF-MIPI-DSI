#include "rx8025t.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

extern i2c_master_bus_handle_t get_shared_i2c_bus(void);
static const char *TAG = "RX8025T";
static i2c_master_dev_handle_t rtc_dev_handle = NULL;

static uint8_t bcd2dec(uint8_t val)
{
    return ((val >> 4) * 10) + (val & 0x0F);
}

static uint8_t dec2bcd(uint8_t val)
{
    return ((val / 10) << 4) | (val % 10);
}
esp_err_t rx8025t_init(void)
{
    i2c_master_bus_handle_t bus = get_shared_i2c_bus();
    if (bus == NULL)
        return ESP_ERR_INVALID_STATE;
    i2c_device_config_t dev_cfg = {
        .dev_addr_length = I2C_ADDR_BIT_LEN_7,
        .device_address = RX8025T_ADDR,
        .scl_speed_hz = 400000,
    };
    esp_err_t err = i2c_master_bus_add_device(bus, &dev_cfg, &rtc_dev_handle);
    if (err != ESP_OK)
        return err;
    uint8_t ctrl1[2] = {RX8025T_REG_CTRL1, 0x20};
    err = i2c_master_transmit(rtc_dev_handle, ctrl1, 2, 1000);
    if (err != ESP_OK)
        return err;
    uint8_t ctrl2[2] = {RX8025T_REG_CTRL2, 0x00};
    ESP_LOGI(TAG, "RX8025T init OK");
    return i2c_master_transmit(rtc_dev_handle, ctrl2, 2, 1000);
}
esp_err_t rx8025t_get_time(rx8025t_time_t *time)
{
    if (rtc_dev_handle == NULL || time == NULL)
        return ESP_ERR_INVALID_STATE;
    uint8_t reg = RX8025T_REG_SEC;
    uint8_t data[7] = {0};
    esp_err_t err = i2c_master_transmit_receive(rtc_dev_handle, &reg, 1, data, 7, 1000);
    if (err != ESP_OK)
        return err;
    time->second = bcd2dec(data[0] & 0x7F);
    time->minute = bcd2dec(data[1] & 0x7F);
    time->hour = bcd2dec(data[2] & 0x3F);
    time->weekday = data[3] & 0x07;
    time->day = bcd2dec(data[4] & 0x3F);
    time->month = bcd2dec(data[5] & 0x1F);
    time->year = bcd2dec(data[6]) + 2000;
    return ESP_OK;
}
esp_err_t rx8025t_set_time(const rx8025t_time_t *time)
{
    if (rtc_dev_handle == NULL || time == NULL)
        return ESP_ERR_INVALID_STATE;
    uint8_t buf[8];
    buf[0] = RX8025T_REG_SEC;
    buf[1] = dec2bcd(time->second);
    buf[2] = dec2bcd(time->minute);
    buf[3] = dec2bcd(time->hour);
    buf[4] = time->weekday & 0x07;
    buf[5] = dec2bcd(time->day);
    buf[6] = dec2bcd(time->month);
    buf[7] = dec2bcd(time->year % 100);
    return i2c_master_transmit(rtc_dev_handle, buf, 8, 1000);
}
