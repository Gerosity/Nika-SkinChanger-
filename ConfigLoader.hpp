#pragma once
struct ConfigLoader {
    const std::string FILE_NAME = "nika.ini";
    std::vector<std::string>* lines = new std::vector<std::string>;
    long m_lastTimeFileEdited = 0;

    ConfigLoader() {
        reloadFile();
    }

    //features
    bool FEATURE_AIMBOT_ON = true;
    bool FEATURE_SENSE_ON = true;
    bool FEATURE_SPECTATOR_ON = true;
    bool FEATURE_QUICKTURN_ON = true;
    bool FEATURE_SKINCHANGER_ON = true;
    bool FEATURE_TRIGGERBOT_ON = true;
    bool FEATURE_NORECOIL_ON = true;
    bool FEATURE_PRINT_LEVELS_ON = true;
    bool FEATURE_SUPER_GLIDE_ON = true;
    bool FEATURE_MAP_RADAR_ON = true;

    //norecoil    
    int NORECOIL_PITCH_REDUCTION = 15;
    int NORECOIL_YAW_REDUCTION = 17;

    //aimbot
    bool AIMBOT_ACTIVATED_BY_ATTACK = true;
    bool AIMBOT_ACTIVATED_BY_ADS = false;
    std::string AIMBOT_ACTIVATED_BY_BUTTON = "XK_Shift_L";
    std::string FEATURE_QUICKTURN_BUTTON = "XK_f";
    std::string FEATURE_PRINT_LEVELS_BUTTON = "XK_p";
    std::string FEATURE_MAP_RADAR_BUTTON = "XK_m";
    float AIMBOT_SMOOTH = 20.211;
    float AIMBOT_SPEED = 40.211;
    float AIMBOT_SMOOTH_EXTRA_BY_DISTANCE = 1000;
    float AIMBOT_FOV = 5.0000;
    bool AIMBOT_PREDICT_BULLETDROP = true;
    bool AIMBOT_PREDICT_MOVEMENT = true;
    bool AIMBOT_ALLOW_TARGET_SWITCH = true;
    int AIMBOT_MAX_DISTANCE = 100;
    int AIMBOT_MIN_DISTANCE = 1;
    //skin ids - for skinchanger - implemented by Gerosity
    //Light ammo weapons
    int SKIN_P2020 = 1;
    int SKIN_RE45 = 1;
    int SKIN_ALTERNATOR = 1;
    int SKIN_R99 = 1;
    int SKIN_R301 = 1;  
    int SKIN_SPITFIRE = 1;
    int SKIN_G7 = 1;
    //Heavy ammo weapons
    int SKIN_CARSMG = 1;
    int SKIN_RAMPAGE = 1;
    int SKIN_3030 = 1;
    int SKIN_HEMLOCK = 1;
    int SKIN_FLATLINE = 1; 
    //Energy ammo weapons
    int SKIN_NEMESIS = 1; 
    int SKIN_VOLT = 1;
    int SKIN_TRIPLETAKE = 1;
    int SKIN_LSTAR = 1;
    int SKIN_DEVOTION = 1;
    int SKIN_HAVOC = 1;
    //Sniper ammo weapons
    int SKIN_SENTINEL = 1;
    int SKIN_CHARGERIFLE = 1;
    int SKIN_LONGBOW = 1;
    //Shotgun ammo weapons
    int SKIN_MOZAMBIQUE = 1;
    int SKIN_EVA8 = 1;
    int SKIN_PEACEKEEPER = 1;
    int SKIN_MASTIFF = 1;
    //Legendary ammo weapons
    int SKIN_WINGMAN = 1;
    int SKIN_PROWLER = 1;
    int SKIN_BOCEK = 1;
    int SKIN_KRABER = 1;
    int SKIN_THROWINGKNIFE = 1;
    int SKIN_THERMITEGRENADE = 1;

    bool IS_GAME_BR;



    void loadVariables(std::string key, std::string val) {
        //features
        FEATURE_AIMBOT_ON = (key.compare("FEATURE_AIMBOT_ON") != 0) ? FEATURE_AIMBOT_ON : toBool(val);
        FEATURE_SENSE_ON = (key.compare("FEATURE_SENSE_ON") != 0) ? FEATURE_SENSE_ON : toBool(val);
        FEATURE_TRIGGERBOT_ON = (key.compare("FEATURE_TRIGGERBOT_ON") != 0) ? FEATURE_TRIGGERBOT_ON : toBool(val);
        FEATURE_NORECOIL_ON = (key.compare("FEATURE_NORECOIL_ON") != 0) ? FEATURE_NORECOIL_ON : toBool(val);

        //norecoil        
        NORECOIL_PITCH_REDUCTION = (key.compare("NORECOIL_PITCH_REDUCTION") != 0) ? NORECOIL_PITCH_REDUCTION : stoi(val);
        NORECOIL_YAW_REDUCTION = (key.compare("NORECOIL_YAW_REDUCTION") != 0) ? NORECOIL_YAW_REDUCTION : stoi(val);

        //aimbot
        AIMBOT_ACTIVATED_BY_ATTACK = (key.compare("AIMBOT_ACTIVATED_BY_ATTACK") != 0) ? AIMBOT_ACTIVATED_BY_ATTACK : toBool(val);
        AIMBOT_ACTIVATED_BY_ADS = (key.compare("AIMBOT_ACTIVATED_BY_ADS") != 0) ? AIMBOT_ACTIVATED_BY_ADS : toBool(val);
        AIMBOT_ACTIVATED_BY_BUTTON = (key.compare("AIMBOT_ACTIVATED_BY_BUTTON") != 0) ? AIMBOT_ACTIVATED_BY_BUTTON : trimConstructive(val);
        AIMBOT_SMOOTH = (key.compare("AIMBOT_SMOOTH") != 0) ? AIMBOT_SMOOTH : stod(val);
        AIMBOT_SPEED = (key.compare("AIMBOT_SPEED") != 0) ? AIMBOT_SPEED : stod(val);
        AIMBOT_SMOOTH_EXTRA_BY_DISTANCE = (key.compare("AIMBOT_SMOOTH_EXTRA_BY_DISTANCE") != 0) ? AIMBOT_SMOOTH_EXTRA_BY_DISTANCE : stod(val);
        AIMBOT_FOV = (key.compare("AIMBOT_FOV") != 0) ? AIMBOT_FOV : stod(val);
        AIMBOT_PREDICT_BULLETDROP = (key.compare("AIMBOT_PREDICT_BULLETDROP") != 0) ? AIMBOT_PREDICT_BULLETDROP : toBool(val);
        AIMBOT_PREDICT_MOVEMENT = (key.compare("AIMBOT_PREDICT_MOVEMENT") != 0) ? AIMBOT_PREDICT_MOVEMENT : toBool(val);
        AIMBOT_ALLOW_TARGET_SWITCH = (key.compare("AIMBOT_ALLOW_TARGET_SWITCH") != 0) ? AIMBOT_ALLOW_TARGET_SWITCH : toBool(val);
        AIMBOT_MAX_DISTANCE = (key.compare("AIMBOT_MAX_DISTANCE") != 0) ? AIMBOT_MAX_DISTANCE : stoi(val);
        AIMBOT_MIN_DISTANCE = (key.compare("AIMBOT_MIN_DISTANCE") != 0) ? AIMBOT_MIN_DISTANCE : stoi(val);
        
        //skin ids - for skinchanger - implemented by Gerosity
        //Light ammo weapons
        SKIN_P2020 = (key.compare("SKIN_P2020") != 0) ? SKIN_P2020 : stoi(val);
        SKIN_RE45 = (key.compare("SKIN_RE45") != 0) ? SKIN_RE45 : stoi(val);
        SKIN_ALTERNATOR = (key.compare("SKIN_ALTERNATOR") != 0) ? SKIN_ALTERNATOR : stoi(val);
        SKIN_R99 = (key.compare("SKIN_R99") != 0) ? SKIN_R99 : stoi(val);
        SKIN_R301 = (key.compare("SKIN_R301") != 0) ? SKIN_R301 : stoi(val);
        SKIN_SPITFIRE = (key.compare("SKIN_SPITFIRE") != 0) ? SKIN_SPITFIRE : stoi(val);
        SKIN_G7 = (key.compare("SKIN_G7") != 0) ? SKIN_G7 : stoi(val);
        //Heavy ammo weapons
        SKIN_CARSMG = (key.compare("SKIN_CARSMG") != 0) ? SKIN_CARSMG : stoi(val);
        SKIN_RAMPAGE = (key.compare("SKIN_RAMPAGE") != 0) ? SKIN_RAMPAGE : stoi(val);
        SKIN_3030 = (key.compare("SKIN_3030") != 0) ? SKIN_3030 : stoi(val);
        SKIN_HEMLOCK = (key.compare("SKIN_HEMLOCK") != 0) ? SKIN_HEMLOCK : stoi(val);
        SKIN_FLATLINE = (key.compare("SKIN_FLATLINE") != 0) ? SKIN_FLATLINE : stoi(val);
        //Energy ammo weapons
        SKIN_NEMESIS = (key.compare("SKIN_NEMESIS") != 0) ? SKIN_NEMESIS : stoi(val);
        SKIN_VOLT = (key.compare("SKIN_VOLT") != 0) ? SKIN_VOLT : stoi(val);
        SKIN_TRIPLETAKE = (key.compare("SKIN_TRIPLETAKE") != 0) ? SKIN_TRIPLETAKE : stoi(val);
        SKIN_LSTAR = (key.compare("SKIN_LSTAR") != 0) ? SKIN_LSTAR : stoi(val);
        SKIN_DEVOTION = (key.compare("SKIN_DEVOTION") != 0) ? SKIN_DEVOTION : stoi(val);
        SKIN_HAVOC = (key.compare("SKIN_HAVOC") != 0) ? SKIN_HAVOC : stoi(val);
        //Sniper ammo weapons
        SKIN_SENTINEL = (key.compare("SKIN_SENTINEL") != 0) ? SKIN_SENTINEL : stoi(val);
        SKIN_CHARGERIFLE = (key.compare("SKIN_CHARGERIFLE") != 0) ? SKIN_CHARGERIFLE : stoi(val);
        SKIN_LONGBOW = (key.compare("SKIN_LONGBOW") != 0) ? SKIN_LONGBOW : stoi(val);
        //Shotgun ammo weapons
        SKIN_MOZAMBIQUE = (key.compare("SKIN_MOZAMBIQUE") != 0) ? SKIN_MOZAMBIQUE : stoi(val);
        SKIN_EVA8 = (key.compare("SKIN_EVA8") != 0) ? SKIN_EVA8 : stoi(val);
        SKIN_PEACEKEEPER = (key.compare("SKIN_PEACEKEEPER") != 0) ? SKIN_PEACEKEEPER : stoi(val);
        SKIN_MASTIFF = (key.compare("SKIN_MASTIFF") != 0) ? SKIN_MASTIFF : stoi(val);
        //Legendary ammo weapons
	SKIN_WINGMAN = (key.compare("SKIN_WINGMAN") != 0) ? SKIN_WINGMAN : stoi(val);
	SKIN_PROWLER = (key.compare("SKIN_PROWLER") != 0) ? SKIN_PROWLER : stoi(val);
	SKIN_BOCEK = (key.compare("SKIN_BOCEK") != 0) ? SKIN_BOCEK : stoi(val);
	SKIN_KRABER = (key.compare("SKIN_KRABER") != 0) ? SKIN_KRABER : stoi(val);
	SKIN_THROWINGKNIFE = (key.compare("SKIN_THROWINGKNIFE") != 0) ? SKIN_THROWINGKNIFE : stoi(val);
	SKIN_THERMITEGRENADE = (key.compare("SKIN_THERMITEGRENADE") != 0) ? SKIN_THERMITEGRENADE : stoi(val);
        
        //gameMode
        IS_GAME_BR = (key.compare("IS_GAME_BR") != 0) ? IS_GAME_BR : toBool(val);
        //random
        FEATURE_SPECTATOR_ON = (key.compare("FEATURE_SPECTATOR_ON") != 0) ? FEATURE_SPECTATOR_ON : toBool(val);
        FEATURE_SUPER_GLIDE_ON = (key.compare("FEATURE_SUPER_GLIDE_ON") != 0) ? FEATURE_SUPER_GLIDE_ON : toBool(val);
        FEATURE_SKINCHANGER_ON = (key.compare("FEATURE_SKINCHANGER_ON") != 0) ? FEATURE_SKINCHANGER_ON : toBool(val);
        FEATURE_QUICKTURN_ON = (key.compare("FEATURE_QUICKTURN_ON") != 0) ? FEATURE_QUICKTURN_ON : toBool(val);    
        FEATURE_QUICKTURN_BUTTON = (key.compare("FEATURE_QUICKTURN_BUTTON") != 0) ? FEATURE_QUICKTURN_BUTTON : trimConstructive(val);
        FEATURE_PRINT_LEVELS_ON = (key.compare("FEATURE_PRINT_LEVELS_ON") != 0) ? FEATURE_PRINT_LEVELS_ON : toBool(val); 
        FEATURE_PRINT_LEVELS_BUTTON = (key.compare("FEATURE_PRINT_LEVELS_BUTTON") != 0) ? FEATURE_PRINT_LEVELS_BUTTON : trimConstructive(val);
        FEATURE_MAP_RADAR_ON = (key.compare("FEATURE_MAP_RADAR_ON") != 0) ? FEATURE_MAP_RADAR_ON : toBool(val); 
        FEATURE_MAP_RADAR_BUTTON = (key.compare("FEATURE_MAP_RADAR_BUTTON") != 0) ? FEATURE_MAP_RADAR_BUTTON : trimConstructive(val);
        }

    void print() {
        printf("\n==================== GRINDER SETTINGS LOADED ========================\n");
        //features
        printf("FEATURE_AIMBOT_ON\t\t\t\t\t%s\n", FEATURE_AIMBOT_ON ? "YES" : "NO");
        printf("FEATURE_NORECOIL_ON\t\t\t\t\t%s\n", FEATURE_NORECOIL_ON ? "YES" : "NO");
        printf("FEATURE_SENSE_ON\t\t\t\t\t%s\n", FEATURE_SENSE_ON ? "YES" : "NO");
        printf("FEATURE_TRIGGERBOT_ON\t\t\t\t\t%s\n\n", FEATURE_TRIGGERBOT_ON ? "YES" : "NO");
        printf("FEATURE_SPECTATOR_ON\t\t\t\t\t%s\n", FEATURE_SPECTATOR_ON ? "YES" : "NO");
        printf("FEATURE_SUPER_GLIDE_ON\t\t\t\t\t%s\n", FEATURE_SUPER_GLIDE_ON ? "YES" : "NO");
        printf("FEATURE_SKINCHANGER_ON\t\t\t\t\t%s\n", FEATURE_SKINCHANGER_ON ? "YES" : "NO");
        printf("FEATURE_QUICKTURN_ON\t\t\t\t\t%s\n", FEATURE_QUICKTURN_ON ? "YES" : "NO");
        printf("FEATURE_QUICKTURN_BUTTON\t\t\t\t%s\n", FEATURE_QUICKTURN_BUTTON.c_str());
        printf("FEATURE_PRINT_LEVELS_ON\t\t\t\t\t%s\n", FEATURE_PRINT_LEVELS_ON ? "YES" : "NO");
        printf("FEATURE_PRINT_LEVELS_BUTTON\t\t\t\t%s\n", FEATURE_PRINT_LEVELS_BUTTON.c_str());
        printf("FEATURE_MAP_RADAR_ON\t\t\t\t\t%s\n", FEATURE_MAP_RADAR_ON ? "YES" : "NO");
        printf("FEATURE_MAP_RADAR_BUTTON\t\t\t\t%s\n", FEATURE_MAP_RADAR_BUTTON.c_str());
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        //gameMode
        printf("IS_GAME_BR\t\t\t\t\t\t%s\n", IS_GAME_BR ? "YES" : "NO");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        //norecoil
        printf("NORECOIL_PITCH_REDUCTION\t\t\t\t%d\n", NORECOIL_PITCH_REDUCTION);
        printf("NORECOIL_YAW_REDUCTION\t\t\t\t\t%d\n", NORECOIL_YAW_REDUCTION);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        //aimbot
        printf("AIMBOT_ACTIVATED_BY_ATTACK\t\t\t\t%s\n", AIMBOT_ACTIVATED_BY_ATTACK ? "YES" : "NO");
        printf("AIMBOT_ACTIVATED_BY_ADS\t\t\t\t\t%s\n", AIMBOT_ACTIVATED_BY_ADS ? "YES" : "NO");
        printf("AIMBOT_ACTIVATED_BY_BUTTON\t\t\t\t%s\n", AIMBOT_ACTIVATED_BY_BUTTON.c_str());
        printf("AIMBOT_SMOOTH\t\t\t\t\t\t%.10f\n", AIMBOT_SMOOTH);
        printf("AIMBOT_SPEED\t\t\t\t\t\t%.10f\n", AIMBOT_SPEED);
        printf("AIMBOT_SMOOTH_EXTRA_BY_DISTANCE\t\t\t\t%.4f\n", AIMBOT_SMOOTH_EXTRA_BY_DISTANCE);
        printf("AIMBOT_FOV\t\t\t\t\t\t%.4f\n", AIMBOT_FOV);
        printf("AIMBOT_PREDICT_BULLETDROP\t\t\t\t%s\n", AIMBOT_PREDICT_BULLETDROP ? "YES" : "NO");
        printf("AIMBOT_PREDICT_MOVEMENT\t\t\t\t\t%s\n", AIMBOT_PREDICT_MOVEMENT ? "YES" : "NO");
        printf("AIMBOT_ALLOW_TARGET_SWITCH\t\t\t\t%s\n", AIMBOT_ALLOW_TARGET_SWITCH ? "YES" : "NO");
        printf("AIMBOT_MAX_DISTANCE\t\t\t\t\t%d\n", AIMBOT_MAX_DISTANCE);
        printf("AIMBOT_MIN_DISTANCE\t\t\t\t\t%d\n", AIMBOT_MIN_DISTANCE);

        printf("=====================================================================\n\n");
    }

    void reloadFile() {
        if (loadFileIntoVector()) {
            parseLines();
            print();
        }
    }

    void parseLines() {
        for (int i = 0; i < lines->size(); i++) {
            std::vector<std::string> lineParts = split(lines->at(i));
            // line key
            std::string key(lineParts.at(0));
            trim(key);
            if (key.empty()) throw "Cannot parse the config. Bad key";
            // line value
            std::string value(lineParts.at(1));
            trim(value);
            if (value.empty()) throw "Cannot parse the config. Bad value";
            loadVariables(key, value);
        }
    }

    bool loadFileIntoVector() {
        struct stat result;
        if (stat(FILE_NAME.c_str(), &result) == 0) {
            long modTime = result.st_mtime;
            bool fileNeedsReload = modTime > m_lastTimeFileEdited;
            m_lastTimeFileEdited = modTime;
            if (!fileNeedsReload) return false;
        }
        lines->clear();
        std::string str;
        std::ifstream myFile(FILE_NAME);
        while (getline(myFile, str)) {
            trim(str);
            if (str.empty()) continue;
            if (str.rfind("#", 0) == 0) continue;
            lines->push_back(str);
        }
        myFile.close();
        return true;
    }

    bool toBool(std::string str) {
        if (toLowerCase(str) == "y") return true;
        if (toLowerCase(str) == "n") return false;
        if (toLowerCase(str) == "yes") return true;
        if (toLowerCase(str) == "no") return false;
        if (toLowerCase(str) == "1") return true;
        if (toLowerCase(str) == "0") return false;
        throw  std::invalid_argument("Cannot parse string to boolean: " + str);
    }

    void trim(std::string& s) {
        ltrim(s);
        rtrim(s);
    }

    std::string trimConstructive(std::string& s) {
        ltrim(s);
        rtrim(s);
        return s;
    }

    void ltrim(std::string& s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch)
            { return !std::isspace(ch); }));
    }

    void rtrim(std::string& s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch)
            { return !std::isspace(ch); })
            .base(),
            s.end());
    }

    std::vector<std::string> split(std::string s) {
        std::stringstream ss(s);
        std::istream_iterator<std::string> begin(ss);
        std::istream_iterator<std::string> end;
        std::vector<std::string> tokens(begin, end);
        return tokens;
    }

    std::string toLowerCase(const std::string& input) {
        std::string result = input;
        std::transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }
};
