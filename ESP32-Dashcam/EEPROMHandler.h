class EEPROMHandler {
public:
    EEPROMHandler();

    void saveSetting(const char* settingName, short value);

    short loadSetting(const char* settingName);

private:
    short getSettingAddress(const char* settingName);
    void initEEPROM();
};
