# FOTOS – SPIFFS Partition Resources

## 🇺🇸 English Version

This folder contains the resource files that will be packaged and flashed onto the **SPIFFS** partition during compilation.

### 1. Slideshow Images (`FOTO1.jpg`, `FOTO2.jpg`)
The folder includes two sample JPEG images that are automatically added to the SPIFFS partition. You can replace them with your own photos, provided you follow these requirements:
* **Resolution and Orientation:** Images must have a resolution of **800x1280** pixels and be rotated vertically (**Portrait** orientation).
* **Size Limit:** The total size of the images must not exceed **2 MB**. If you want to use larger files, you must allocate more space for the SPIFFS partition in the `partitions.csv` file.

### 2. Wi-Fi Network Configuration (`prefs.ini`)
The `prefs.ini` file stores your Wi-Fi credentials, which the application uses to connect to the **NTP** time server and the **weather service**. You can configure them in two ways:

#### Option A: Before Compilation (Editing `prefs.ini`)
Open the `prefs.ini` file before building the project and replace the placeholder lines with your actual network details:

```text
YOUR_NETWORK_NAME
YOUR_NETWORK_PASSWORD
```
*(Note: The first line is your Wi-Fi SSID, and the second line is your Wi-Fi password).*

#### Option B: Via Built-in SoftAP & HTTP Configuration Portal
You can set or update your Wi-Fi credentials directly on the device without recompiling:
1. Tap the **WiFi** option in the touch menu on your **ESP32-P4** screen.
2. The device will start a **SoftAP (Software Access Point)** with a built-in **HTTP configuration server** (Captive Portal).
3. Connect to this Wi-Fi network from your smartphone or PC *(on Windows, press `Win + A` and click the `>` icon next to the Wi-Fi tile to find available networks)*.
4. Most smartphones will automatically open the configuration page. If not, open a web browser and go to: **`http://192.168.4.1`**
5. Enter your **SSID** and **PASSWORD** in the web form and submit. The ESP32 access point will automatically disconnect and save your credentials to `/spiffs/prefs.ini`.

### 3. Weather Location Coordinates (`weather.ini`)
The `weather.ini` file is used for fetching local temperature data and currently holds the following coordinates:

```ini
lat=53.12
lon=18.01
```

If you want to display the weather for a different location, simply edit these values in `weather.ini` to match your desired latitude and longitude before flashing.

Note **(Updated Firmware):** In the latest version, weather locations (**Bydgoszcz, London**, and **Pakistan / Islamabad**) and timezones are selected directly from the on-screen **NTP** menu and stored in **NVS** (automatically updating /spiffs/weather.ini when pressing **DONE**)
---

## 🇵🇱 Wersja Polska

Ten folder zawiera pliki zasobów, które zostaną spakowane i wgrane na partycję **SPIFFS** podczas kompilacji projektu.

### 1. Zdjęcia pokazu slajdów (`FOTO1.jpg`, `FOTO2.jpg`)
W folderze znajdują się 2 przykładowe zdjęcia JPG, które zostaną dodane do partycji SPIFFS. Możesz wymienić je na własne, ale musisz pamiętać o następujących zasadach:
* **Rozdzielczość i orientacja:** Zdjęcia muszą mieć dokładną rozdzielczość **800x1280** pikseli i być obrócone w pionie (**Portrait**).
* **Limit rozmiaru:** Łączny rozmiar zdjęć nie może przekroczyć **2 MB**. W przeciwnym wypadku musisz przydzielić więcej miejsca dla partycji SPIFFS w pliku `partitions.csv`.

### 2. Konfiguracja sieci Wi-Fi (`prefs.ini`)
Plik `prefs.ini` przechowuje dane sieci bezprzewodowej, które aplikacja wykorzystuje do łączenia się z serwerem czasu **NTP** oraz **stacją pogodową**. Możesz je uzupełnić lub zmienić na dwa sposoby:

#### Sposób A: Bezpośrednio podczas kompilacji (edycja `prefs.ini`)
Otwórz plik `prefs.ini` przed zbudowaniem projektu i zamień dwie domyślne linie (`SSID` oraz `PASSWORD`) na swoje dane:

```text
TWOJA_NAZWA_SIECI
HASLO_DO_TWOJEJ_SIECI
```

#### Sposób B: Przez wbudowany punkt dostępowy (SoftAP) i portal HTTP
Dane sieci możesz wpisać lub zaktualizować bezpośrednio z poziomu urządzenia:
1. Uruchom opcję **WiFi** w menu na ekranie **ESP32-P4**.
2. Urządzenie uruchomi własny punkt dostępowy **SoftAP (Access Point)** z wbudowanym **serwerem HTTP** (tzw. *Captive Portal*).
3. Połącz się z siecią rozgłaszaną przez ESP32 za pomocą telefonu lub komputera *(w systemie Windows naciśnij skrót `Windows + A` i kliknij kafelek ze znakiem `>` obok ikony Wi-Fi, aby rozwinąć listę sieci)*.
4. Większość telefonów automatycznie otworzy stronę konfiguracyjną. Jeśli tak się nie stanie, wpisz w przeglądarce adres: **`http://192.168.4.1`**
5. Podaj w formularzu swoje **SSID** oraz **PASSWORD** i zatwierdź. Sieć ESP32 rozłączy się automatycznie, a podane dane zostaną zapisane w pliku `/spiffs/prefs.ini`.

### 3. Współrzędne lokalizacji dla pogody (`weather.ini`)
Plik `weather.ini` służy do odczytywania temperatury dla wybranej lokalizacji. Obecnie zawiera on następujące współrzędne:

```ini
lat=53.12
lon=18.01
```

Jeżeli chcesz sprawdzać pogodę dla innego miejsca, zmień te wartości w pliku `weather.ini` na własne współrzędne geograficzne (szerokość i długość geograficzną).

Uwaga **(Aktualizacja programu):** W najnowszej wersji wybór lokalizacji pogody (**Bydgoszcz, Londyn, Pakistan / Islamabad**) oraz strefy czasowej odbywa się bezpośrednio z poziomu ekranowego menu **NTP** i jest zapisywany w pamięci **NVS** (przy kliknięciu **DONE** plik /spiffs/weather.ini aktualizowany jest automatycznie).