#pragma once

#include <stdbool.h>
#include <inttypes.h>

// Uruchamia jednorazowe zadanie synchronizacji czasu NTP w tle na rdzeniu 1.
// Nie blokuje ekranu i nie zawiesza procesora, nawet gdy brak sieci Wi-Fi.
void start_ntp_sync_task_async(void);

// Zwraca true, jeśli aktualnie trwa łączenie z Wi-Fi / NTP
bool is_ntp_sync_running(void);
bool ensure_wifi_stack_initialized(void);

// Nowe funkcje dla pogody Open-Meteo:
bool fetch_weather_temperature(float *out_temp);
bool is_weather_fetch_running(void);

typedef struct
{
    const char *name;
    float lat;
    float lon;
    const char *tz;
} LocationPreset;

extern const LocationPreset LOCATIONS[3];
extern volatile uint8_t g_weather_loc_idx; // 0=BYDGOSZCZ, 1=LONDYN, 2=PAKISTAN
extern volatile uint8_t g_tz_loc_idx;      // 0=BYDGOSZCZ, 1=LONDYN, 2=PAKISTAN

void apply_timezone_by_idx(uint8_t idx);
void load_location_prefs_from_NVS(void);
void save_location_prefs_to_NVS(uint8_t weather_idx, uint8_t tz_idx);
