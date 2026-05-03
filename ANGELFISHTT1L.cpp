// group section tt1l , group name : ANGELFISH
// member 1 and group leader : name [alhalah , kutaiba],id [242UC241CY], phone
// [01128570387] , email [ALHALAH.KUTAIBA@student.mmu.edu.my] member 2 : name[Ng
// Wen Pin], id [242UC2459U], phone [0108312028], email
// [ng.wen.pin@student.mmu.edu.my] member 3 : name[Tee Wai Hong] ,
// id[243UC247C6], phone [0163520230], email [tee.wai.hong@student.mmu.edu.my ]
// member 4 : name[Adeena Shahira Binti Mohd Hafiz], id  [242UC244RK], phone
// [019-3233705], email [adeena.shahira.mohd@student.mmu.edu.my]
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Forward declarations
// ======================================================================================
// MEMBER 4: DATA OFFICER (Parsing Enums & Structs)
// ======================================================================================
class Ship;

// Enums for types logic
// define core game labels for each crew types, weapon types and factions
enum CrewType {
  PILOT,
  GUNNER,
  TORPEDO_HANDLER,
  UNKNOWN_CREW
}; // enum is used to define a set of named integer constants can be replaced
   // with strings but enums are more efficient because they are stored as
   // integers
enum WeaponType { CANNON, TORPEDO };
enum Faction { ZAPEZOID, ROGOATUSKAN, UNKNOWN_FACTION };

// ==========================================
// Helper Functions
// ==========================================
// define split function to chop CSV data into clean, separate words
vector<string> split(const string &str, char delimiter) {
  vector<string> tokens; // creates an empty list called tokens, to store the
                         // pieces after they're cut
  string token;
  istringstream tokenStream(str);
  while (getline(tokenStream, token,
                 delimiter)) { // loop that runs the string until it hits a
                               // comma, cut it and calls it token
    // Remove standard whitespace/newlines from ends
    int first = token.find_first_not_of(
        " \t\r\n"); // finds position of the first real letter
    if (first ==
        string::npos) { // adds blank entry to the list if it's empty space
      tokens.push_back("");
    } else {
      int last = token.find_last_not_of(" \t\r\n");
      tokens.push_back(token.substr(first, (last - first + 1)));
    }
  }
  return tokens;
}

// forward declaration for normalize (defined at EOF)
string normalize(const string &s);

// ==========================================
// Crew Class
// ==========================================
class Crew {
private:
  string id;
  string name;
  CrewType type;

public:
<<<<<<< HEAD
  Crew(string _id, string _name, string _typeStr) : id(_id), name(_name) {
    if (_typeStr == "pilot" || _typeStr == "Pilot")
      type = PILOT;
    else if (_typeStr == "gunner" || _typeStr == "Gunner")
      type = GUNNER;
    else if (_typeStr == "torpedo handler" || _typeStr == "Torpedo Handler")
      type = TORPEDO_HANDLER;
    else
      type = UNKNOWN_CREW;
  }

  string getID() const { return id; }
  string getName() const { return name; }
  CrewType getType() const { return type; }

  string getTypeStr() const {
    switch (type) {
    case PILOT:
      return "Pilot";
    case GUNNER:
      return "Gunner";
    case TORPEDO_HANDLER:
      return "Torpedo Handler";
    default:
      return "Unknown";
      == == == = Crew(string _id, string _name, string _typeStr)
          : id(_id),
            name(_name) {
        if (_typeStr == "pilot" || _typeStr == "Pilot")
          type = PILOT; // if user type "pilot", it will convert into game's
                        // internal PILOT code
        else if (_typeStr == "gunner" || _typeStr == "Gunner")
          type = GUNNER;
        else if (_typeStr == "torpedo handler" || _typeStr == "Torpedo Handler")
          type = TORPEDO_HANDLER;
        else
          type =
              UNKNOWN_CREW; // if unknown input inserted, it labels UNKNOWN_CREW
      }

      string getID() const { return id; }
      string getName() const { return name; }
      CrewType getType() const { return type; }

      string getTypeStr() const { // takes game's internal code like PILOT and
                                  // turn it into "Pilot", when printed
        switch (type) {
        case PILOT:
          return "Pilot";
        case GUNNER:
          return "Gunner";
        case TORPEDO_HANDLER:
          return "Torpedo Handler";
        default:
          return "Unknown";
        }
>>>>>>> 933b7f9f5e970f827258162048c538d45977118b
      }
    }
  };

  // ==========================================
  // ======================================================================================
  // MEMBER 1 (LEADER): SHIPWRIGHT (Inheritance & Classes)
  // ======================================================================================
  // Abstract Ship Class the ship types will inherite and modify this for a
  // cleaner working environment
  // ==========================================

  class Ship {
  protected:
    string id;
    string name;
    Faction faction;
    int maxHP;
    int currentHP;

    // Weapon stats
    int lightCannonPower;
    int numLightCannons;
    int torpedoPower; // 0 if none
    int numTorpedoes; // 0 if none

    // Crew implementation using native pointers (vector of pointers)
    vector<Crew *> pilots;
    vector<Crew *> gunners;
    vector<Crew *> torpHandlers;

    // Crew requirements (max capacity)
    int maxPilots;
    int maxGunners;
    int maxTorpHandlers;

  public: // ship( id , name , faction , maxHP , lightCannonPower ,
          // numLightCannons , torpedoPower , numTorpedoes , maxPilots ,
          // maxGunners , maxTorpHandlers)
    Ship(string _id, string _name, Faction _faction, int _hp, int _cannonPwr,
         int _numCannons, int _torpPwr, int _numTorps, int _maxPilots,
         int _maxGunners, int _maxTorpHandlers)
        : id(_id), name(_name), faction(_faction), maxHP(_hp), currentHP(_hp),
          lightCannonPower(_cannonPwr), numLightCannons(_numCannons),
          torpedoPower(_torpPwr), numTorpedoes(_numTorps),
          maxPilots(_maxPilots), maxGunners(_maxGunners),
          maxTorpHandlers(_maxTorpHandlers) {}

    virtual ~Ship() {
      // We do not delete Crew pointers here because Crew objects are managed
      // externally because when we delete a ship we do not want to delete the
      // crew as well
    }

    // Pure Virtual Methods
    virtual string getTypeName() const = 0;
    virtual double getEvasionChance(WeaponType weapon) const = 0;

    // Core Methods
    string getID() const { return id; }
    string getName() const { return name; }
    int getHP() const { return currentHP; }
    int getMaxHP() const { return maxHP; }
    bool isDestroyed() const { return currentHP <= 0; }
    Faction getFaction() const { return faction; }

    void receiveDamage(int dmg) {
      currentHP -= dmg;
      if (currentHP < 0)
        currentHP = 0;
    }

    // Attempt to add crew. Returns true if added, false if full or wrong type.
    bool addCrew(Crew *c) {
      if (c->getType() == PILOT && pilots.size() < maxPilots) {
        pilots.push_back(c);
        return true;
      } else if (c->getType() == GUNNER && gunners.size() < maxGunners) {
        gunners.push_back(c);
        return true;
      } else if (c->getType() == TORPEDO_HANDLER &&
                 torpHandlers.size() < maxTorpHandlers) {
        torpHandlers.push_back(c);
        return true;
      }
      return false;
    }

    // Operator Overloading as requested: assign crew to ship does that by
    // calling the addCrew function  for every crew member
    Ship &operator+=(Crew *c) {
      addCrew(
          c); // calls the addCrew function to add the crew member to the ship
      return *this; // returns the ship
    }

    // Check if fully crewed or at least functional
    bool hasPilot() const { return !pilots.empty(); }

    // Helpers for battle logic
    int getActiveCannons() const {
      return min((int)gunners.size(),
                 numLightCannons); // returns the minimum of the number of
                                   // gunners and the number of light cannons
    }

    int getActiveTorpedoes() const {
      return min((int)torpHandlers.size(),
                 numTorpedoes); // returns the minimum of the number of torpedo
                                // handlers and the number of torpedoes
    }

    int getCannonPower() const {
      return lightCannonPower;
    } // returns the light cannon power
    int getTorpedoPower() const {
      return torpedoPower;
    } // returns the torpedo power

    Crew *getGunner(int i) const {
      if (i >= 0 && i < gunners.size())
        return gunners[i]; // returns the gunner at index i if the index is
                           // valid
      return nullptr;      // returns nullptr if the index is invalid
    }

    Crew *getTorpHandler(int i) const {
      if (i >= 0 && i < torpHandlers.size())
        return torpHandlers[i]; // returns the torpedo handler at index i if the
                                // index is valid
      return nullptr;
    }

    // Pilot penalty logic
    // "2-pilot vessels will be lowered in ability to avoid being hit by 25% if
    // they only have 1 pilot"
    double getPilotEvasionModifier() const {
      if (maxPilots == 2 && pilots.size() == 1) {
        return 1.25; // Increase hit chance by 25%
      }
      return 1.0;
    }

    // Debug print / Report print
    void printDetails(ostream &os = cout)
        const { // os = cout by default so that it prints to the console, but
                // can be changed to print to a file
      os << "[" << id << "] "
         << name; // output the name and id for the ship in the console
      // Pad name to align with other ships
      int padding =
          20 - name.length(); // works by adding spaces to the end of
                              // the name to make it 20 characters long
      for (int i = 0; i < padding; i++)
        os << " "; // adds spaces to the end of the name to make it 20
                   // characters long
      os << "(" << getTypeName() << ")\n"; // outputs the type of the ship

      os << "      HP: " << currentHP << "/" << maxHP << "\n";

      // Pilots
      os << "      Pilots (" << pilots.size() << "/" << maxPilots << ")";
      if (!pilots.empty())
        os << ": "; // outputs ": " if there are pilots
      for (int i = 0; i < pilots.size(); i++) {
        os << pilots[i]->getName()
           << (i < pilots.size() - 1 ? ", "
                                     : ""); // outputs the name of the pilot and
                                            // ", " if there are more pilots
      }
      os << "\n";

      // Gunners
      if (maxGunners > 0) {
        os << "      Gunners (" << gunners.size() << "/" << maxGunners << ")";
        if (!gunners.empty())
          os << ": ";
        for (int i = 0; i < gunners.size(); i++) {
          os << gunners[i]->getName() << (i < gunners.size() - 1 ? ", " : "");
        }
        os << "\n";
      }

      // Torpedo Handlers
      if (maxTorpHandlers > 0) {
        os << "      Torp Handlers (" << torpHandlers.size() << "/"
           << maxTorpHandlers << ")";
        if (!torpHandlers.empty())
          os << ": ";
        for (int i = 0; i < torpHandlers.size(); i++) {
          os << torpHandlers[i]->getName()
             << (i < torpHandlers.size() - 1 ? ", " : "");
        }
        os << "\n";
      }
    }
  };

  // ==========================================
  // Zapezoid Ships
  // ==========================================
  class Guerriero : public Ship {
  public:
    Guerriero(
        string _id,
        string _name) // ship( id , name , faction , maxHP , lightCannonPower ,
                      // numLightCannons , torpedoPower , numTorpedoes ,
                      // maxPilots , maxGunners , maxTorpHandlers)

        : Ship(_id, _name, ZAPEZOID, 123, 96, 1, 0, 0, 1, 1, 0) {}
    string getTypeName() const override { return "Guerriero"; }

    double getEvasionChance(WeaponType weapon) const override {
      // Guerriero: 26% light cannon, 6% torpedo
      if (weapon == CANNON)
        return 26.0;
      if (weapon == TORPEDO)
        return 6.0;
      return 100.0;
    }
  };

  class Medio : public Ship {
  public:
    Medio(string _id,
          string _name) // ship( id , name , faction , maxHP , lightCannonPower
                        // , numLightCannons , torpedoPower , numTorpedoes ,
                        // maxPilots , maxGunners , maxTorpHandlers)
        : Ship(_id, _name, ZAPEZOID, 214, 134, 2, 0, 0, 1, 2, 0) {}

    string getTypeName() const override { return "Medio"; }

    double getEvasionChance(WeaponType weapon) const override {
      // Medio: 31% light cannon, 11% torpedo
      if (weapon == CANNON)
        return 31.0;
      if (weapon == TORPEDO)
        return 11.0;
      return 100.0;
    }
  };

  class Corazzata : public Ship {
  public:
    Corazzata(
        string _id,
        string _name) // ship( id , name , faction , maxHP , lightCannonPower ,
                      // numLightCannons , torpedoPower , numTorpedoes ,
                      // maxPilots , maxGunners , maxTorpHandlers)
        : Ship(_id, _name, ZAPEZOID, 1031, 164, 10, 293, 4, 2, 10, 4) {}

    string getTypeName() const override { return "Corazzata"; }

    double getEvasionChance(WeaponType weapon) const override {
      // Corazzata: 50% light cannon, 25% torpedo
      double chance =
          (weapon == CANNON)
              ? 50.0
              : 25.0; // sets the evasion chance based on the weapon type
      // Apply pilot penalty
      chance *= getPilotEvasionModifier(); // applies the pilot penalty to the
                                           // evasion chance
      return chance;                       // returns the evasion chance
    }
  };

  // ==========================================
  // Rogoatuskan Ships
  // ==========================================
  class Jager : public Ship {
  public:
    Jager(string _id,
          string _name) // ship( id , name , faction , maxHP , lightCannonPower
                        // , numLightCannons , torpedoPower , numTorpedoes ,
                        // maxPilots , maxGunners , maxTorpHandlers)
        : Ship(_id, _name, ROGOATUSKAN, 112, 101, 1, 0, 0, 1, 1, 0) {}

    string getTypeName() const override { return "Jager"; }

    double getEvasionChance(WeaponType weapon) const override {
      // Jager: 24% light cannon, 5% torpedo
      if (weapon == CANNON)
        return 24.0;
      if (weapon == TORPEDO)
        return 5.0;
      return 100.0;
    }
  };

  class Kreuzer : public Ship {
  public:
    Kreuzer(
        string _id,
        string _name) /// ship( id , name , faction , maxHP , lightCannonPower
                      /// , numLightCannons , torpedoPower , numTorpedoes ,
                      /// maxPilots , maxGunners , maxTorpHandlers)
        : Ship(_id, _name, ROGOATUSKAN, 212, 132, 2, 0, 0, 1, 2, 0) {}

    string getTypeName() const override { return "Kreuzer"; }

    double getEvasionChance(WeaponType weapon) const override {
      // Kreuzer: 29% light cannon, 10% torpedo
      if (weapon == CANNON)
        return 29.0;
      if (weapon == TORPEDO)
        return 10.0;
      return 100.0;
    }
  };

  class Fregatte : public Ship {
  public:
    Fregatte(string _id, string _name)
        : Ship(_id, _name, ROGOATUSKAN, 1143, 159, 11, 282, 5, 2, 11, 5) {}

    string getTypeName() const override { return "Fregatte"; }

    double getEvasionChance(WeaponType weapon) const override {
      // Fregatte: 60% light cannon, 30% torpedo
      double chance = (weapon == CANNON) ? 60.0 : 30.0;
      chance *= getPilotEvasionModifier();
      return chance;
    }
  };

  // ==========================================
  // Game / Battle Engine Class
  // ==========================================

  // ======================================================================================
  // MEMBER 4: DATA OFFICER (File I/O & DualStream)
  // ======================================================================================

  // Helper class to write to both console and file simultaneously
  struct DualStream {
    std::ostream &console; // reference to the console output stream
    std::ofstream &file;   // reference to the file output stream

    // Constructor to initialize references
    DualStream(std::ostream &c, std::ofstream &f) : console(c), file(f) {}

    template <typename T> DualStream &operator<<(const T &data) {
      console << data; // output to console
      if (file.is_open())
        file << data; // output to file if open
      return *this;
    }

<<<<<<< HEAD
    // specific overload for manipulators acts like std::endl
    DualStream &operator<<(std::ostream &(*manip)(std::ostream &)) {
      manip(console); // output to console
      if (file.is_open())
        manip(file); // output to file if open
      return *this;
    }
    == == == =
                 // specific overload for manipulators acts like std::endl
        DualStream & operator<<(std::ostream &(*manip)(std::ostream &)) {
      // start a new line -- on both screen and file
      manip(console); // output to console
      if (file.is_open())
        manip(file); // output to file if open
      return *this;
    }
>>>>>>> 933b7f9f5e970f827258162048c538d45977118b
  };

  // ======================================================================================
  // MEMBER 1 & 3: GAME ARCHITECT (Game Class Structure)
  // ======================================================================================
  class Game {
  private:
    vector<Ship *> zapShips;
    vector<Ship *> rogShips;
    vector<Crew *> zapCrew;
    vector<Crew *> rogCrew;

    vector<Ship *> allShips; // vector to store all ships

    ofstream logFile; // file stream to write to the log file
    DualStream dout;  // DualStream object to write to both console and file
                      // simultaneously

  public:
    Game()
        : dout(cout, logFile) {
    } // constructor to initialize the dualstream object, dout is a reference to
      // cout and logFile
    ~Game() {
      if (logFile.is_open())
        logFile.close(); // close the log file if open
      for (Ship *s : allShips)
        delete s; // delete all ships
      for (Crew *c : zapCrew)
        delete c; // delete all zap crew
      for (Crew *c : rogCrew)
        delete c; // delete all rog crew
    }

    // ======================================================================================
    // MEMBER 4: DATA OFFICER (Parsing Logic)
    // ======================================================================================
    void loadShips(string filename,
                   Faction faction) { // filename = zShips.csv or rShips.csv
      ifstream file(filename);
      if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        exit(1);
      }

      string line;
      while (getline(file, line)) {
        if (line.empty())
          continue;                              // skip empty lines
        vector<string> parts = split(line, ','); // split the line into parts
        if (parts.size() < 3)
          continue; // skip lines with less than 3 parts and ingores any extra
        string id = parts[0];   // get the id
        string type = parts[1]; // get the type
        string name = parts[2]; // get the name
        // Debug print to verify parsing of CSV columns
        cout << "DEBUG loadShips(" << filename << "): id='" << id << "' type='"
             << type << "' name='" << name << "'" << endl;

        Ship *newShip = nullptr;

        // Use normalized type string for robust matching
        string tnorm = normalize(type);

        if (faction == ZAPEZOID) {
          if (tnorm.find("guerr") != string::npos)
            newShip = new Guerriero(id, name);
          else if (tnorm.find("medio") != string::npos)
            newShip = new Medio(id, name);
          else if (tnorm.find("corazz") != string::npos)
            newShip = new Corazzata(id, name);
        } else {
          if (tnorm.find("jag") != string::npos)
            newShip = new Jager(id, name);
          else if (tnorm.find("kreuz") != string::npos)
            newShip = new Kreuzer(id, name);
          else if (tnorm.find("freg") != string::npos)
            newShip = new Fregatte(id, name);
        }

        if (newShip) {
          // Debug: report concrete type constructed
          cout << "DEBUG created(" << filename << "): id='" << id
               << "' -> objectType='" << newShip->getTypeName() << "'" << endl;
          if (faction == ZAPEZOID) {
            zapShips.push_back(
                newShip); // add the new ship to the zap ships vector
            cout << "DEBUG pushed to zapShips: id='" << id << "' vecType='"
                 << zapShips.back()->getTypeName()
                 << "' size=" << zapShips.size() << endl;
          } else {
            rogShips.push_back(
                newShip); // add the new ship to the rog ships vector
            cout << "DEBUG pushed to rogShips: id='" << id << "' vecType='"
                 << rogShips.back()->getTypeName()
                 << "' size=" << rogShips.size() << endl;
          }
          allShips.push_back(
              newShip); // add the new ship to the all ships vector
          cout << "DEBUG pushed to allShips: id='" << id << "' allType='"
               << allShips.back()->getTypeName()
               << "' allSize=" << allShips.size() << endl;
        }
      }
      file.close(); // close the file
    }

<<<<<<< HEAD
    void loadCrew(string filename,
                  Faction faction) { // filename = zCrew.csv or rCrew.csv
      ifstream file(filename);
      if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        exit(1);
        == == == = string line;
        while (getline(file, line)) { // reads file line by line
          if (line.empty())
            continue;                              // skip empty lines
          vector<string> parts = split(line, ','); // split the line into parts
          if (parts.size() < 3)
            continue; // skip lines with less than 3 parts and ingores any extra
          string id = parts[0];   // get the id
          string type = parts[1]; // get the type
          string name = parts[2]; // get the name
          // Debug print to verify parsing of CSV columns
          cout << "DEBUG loadShips(" << filename << "): id='" << id
               << "' type='" << type << "' name='" << name << "'" << endl;

          Ship *newShip = nullptr;

          // Use normalized type string for robust matching
          string tnorm = normalize(type);

          if (faction == ZAPEZOID) { // checks which team the ship belongs to
            if (tnorm.find("guerr") != string::npos)
              newShip = new Guerriero(id, name); // builds specific ship object
            else if (tnorm.find("medio") != string::npos)
              newShip = new Medio(id, name);
            else if (tnorm.find("corazz") != string::npos)
              newShip = new Corazzata(id, name);
          } else {
            if (tnorm.find("jag") != string::npos)
              newShip = new Jager(id, name);
            else if (tnorm.find("kreuz") != string::npos)
              newShip = new Kreuzer(id, name);
            else if (tnorm.find("freg") != string::npos)
              newShip = new Fregatte(id, name);
          }

          if (newShip) {
            // Debug: report concrete type constructed
            cout << "DEBUG created(" << filename << "): id='" << id
                 << "' -> objectType='" << newShip->getTypeName() << "'"
                 << endl;
            if (faction == ZAPEZOID) {
              zapShips.push_back(
                  newShip); // add the new ship to the zap ships vector
              cout << "DEBUG pushed to zapShips: id='" << id << "' vecType='"
                   << zapShips.back()->getTypeName()
                   << "' size=" << zapShips.size() << endl;
            } else {
              rogShips.push_back(
                  newShip); // add the new ship to the rog ships vector
              cout << "DEBUG pushed to rogShips: id='" << id << "' vecType='"
                   << rogShips.back()->getTypeName()
                   << "' size=" << rogShips.size() << endl;
            }
            allShips.push_back(
                newShip); // add the new ship to the all ships vector
            cout << "DEBUG pushed to allShips: id='" << id << "' allType='"
                 << allShips.back()->getTypeName()
                 << "' allSize=" << allShips.size() << endl;
          }
        }
        file.close(); // close the file
>>>>>>> 933b7f9f5e970f827258162048c538d45977118b
      }

      string line;
      while (getline(file, line)) {
        if (line.empty())
          continue;
        vector<string> parts = split(line, ',');
        if (parts.size() < 3)
          continue;

<<<<<<< HEAD
        string id = parts[0];
        string name = parts[1];
        string typeStr = parts[2];

        Crew *newCrew = new Crew(id, name, typeStr); // create a new crew
        if (faction == ZAPEZOID)
          zapCrew.push_back(newCrew); // add the new crew to the zap crew vector
        else
          rogCrew.push_back(newCrew); // add the new crew to the rog crew vector
      }
      file.close(); // close the file
    }

    // ======================================================================================
    // MEMBER 2: QUARTERMASTER (Crew Assignment Logic)
    // ======================================================================================
    void assignFactionCrew(vector<Ship *> &ships, vector<Crew *> &crew) {
      vector<Crew *> pilots, gunners, torpHandlers;
      for (Crew *c : crew) { // Replaced auto with Crew*
        if (c->getType() == PILOT)
          pilots.push_back(c); // add the crew to the pilots vector
        else if (c->getType() == GUNNER)
          gunners.push_back(c); // add the crew to the gunners vector
        else if (c->getType() == TORPEDO_HANDLER)
          torpHandlers.push_back(c); // add the crew to the torpHandlers vector
        == == == = string line; // creates temporary string variable to hold one
                                // full row of text from CSV file
        while (getline(file, line)) { // reads file line by line
          if (line.empty())
            continue;
          vector<string> parts =
              split(line, ','); // to separate the ID, name, and type
          if (parts.size() < 3)
            continue;

          string id = parts[0];
          string name = parts[1];
          string typeStr = parts[2];

          Crew *newCrew = new Crew(id, name, typeStr); // create a new crew
          if (faction == ZAPEZOID)
            zapCrew.push_back(
                newCrew); // add the new crew to the zap crew vector
          else
            rogCrew.push_back(
                newCrew); // add the new crew to the rog crew vector
        }
        file.close(); // close the file
>>>>>>> 933b7f9f5e970f827258162048c538d45977118b
      }

      // Explicit Iterators instead of 'auto'
      vector<Crew *>::iterator pilotIt = pilots.begin();

      // Priority 1: Mandatory Pilot Assignment
      // Rule: Every ship must have at least one pilot to be functional.
      // Logic: Iterate through all ships and assign the first available pilot
      // to each.
      for (Ship *ship : ships) {
        if (pilotIt != pilots.end()) {
          *ship += *pilotIt; // Use Operator+ to add the pilot to the ship
          pilotIt++;         // Move to the next available pilot
        }
      }

      // Priority 2: Fill Remaining Pilot Slots
      // Rule: If there are extra pilots after ensuring every ship has one, fill
      // the remaining seats.
      for (Ship *ship : ships) {
        // Keep adding pilots to the current ship until it's full or we run out
        // of pilots
        while (pilotIt != pilots.end() && ship->addCrew(*pilotIt)) {
          pilotIt++;
        }
      }

      // Priority 3: Distribute Gunners (Round Robin)
      // Rule: Distribute gunners evenly across all ships.
      // Logic: Place one gunner on a ship, then move to the next ship, circling
      // back to the first ship if needed.
      if (!gunners.empty()) {
        int shipIdx = 0;
        vector<Crew *>::iterator gunnerIt = gunners.begin();
        bool assignedAny = true;

        // Continue looping as long as we have gunners AND we successfully
        // assigned at least one in the last pass
        while (gunnerIt != gunners.end() && assignedAny) {
          assignedAny = false; // Reset flag for this pass

          // Try to add one gunner to each ship in the fleet
          for (int i = 0; i < ships.size(); ++i) {
            if (gunnerIt == gunners.end())
              break; // Stop if we run out of gunners

            if (ships[shipIdx]->addCrew(*gunnerIt)) {
              gunnerIt++;         // Move to next gunner
              assignedAny = true; // We successfully placed someone, so we
                                  // should try another pass
            }

            // Move to the next ship index, wrapping around to 0 if we reach the
            // end
            shipIdx = (shipIdx + 1) % ships.size();
          }
        }
      }

      // Priority 4: Distribute Torpedo Handlers (Round Robin)
      // Rule: Distribute torpedo handlers evenly, similar to gunners.
      if (!torpHandlers.empty()) {
        int shipIdx = 0;
        vector<Crew *>::iterator torpIt = torpHandlers.begin();
        bool assignedAny = true;

        while (torpIt != torpHandlers.end() && assignedAny) {
          assignedAny = false;

          for (int i = 0; i < ships.size(); ++i) {
            if (torpIt == torpHandlers.end())
              break;

            if (ships[shipIdx]->addCrew(*torpIt)) {
              torpIt++;
              assignedAny = true;
            }

            // Wrap around to distribute evenly
            shipIdx = (shipIdx + 1) % ships.size();
          }
        }
      }
    }

    void assignCrew() {
      assignFactionCrew(zapShips, zapCrew);
      assignFactionCrew(rogShips, rogCrew);
    }

    void printFleetReport() {
      dout << "========================================" << endl;
      dout << "       FLEET CONFIGURATION REPORT       " << endl;
      dout << "========================================" << endl << endl;

      dout << "--- ZAPEZOID FLEET ---" << endl;
      for (Ship *s : zapShips) { // Replaced auto with Ship*
        s->printDetails(cout);
        if (logFile.is_open())
          s->printDetails(logFile);
        dout << "--------------------------------------------------" << endl;
      }

      dout << endl;

      dout << "--- ROGOATUSKAN FLEET ---" << endl;
      for (Ship *s : rogShips) { // Replaced auto with Ship*
        s->printDetails(cout);
        if (logFile.is_open())
          s->printDetails(logFile);
        dout << "--------------------------------------------------" << endl;
      }

      dout << "========================================" << endl;
      dout << "            BATTLE COMMENCING            " << endl;
      dout << "========================================" << endl << endl;
    }

    //======================================================================================
    // MEMBER 3: ARCHITECT (battle Logic & Loop)
    //======================================================================================
    // shoot helper
    void executeShots(vector<Ship *> &shooters, vector<Ship *> &targets) {
      for (Ship *s : shooters) { // replaced auto with Ship*
        // need a valid target that is not destroy

        // build list to collect currently living ships to targets
        vector<Ship *> liveTargets;
        for (Ship *t : targets)
          if (!t->isDestroyed())
            liveTargets.push_back(
                t); // replaced auto with Ship*, store the live
                    // targets by checking if their health is >0

        if (liveTargets.empty())
          return; // victory if no enemy targets alive

        // cannons
        int guns = s->getActiveCannons();
        for (int i = 0; i < guns; ++i) {
          if (liveTargets.empty())
            break;

          // random pick target
          Ship *target = liveTargets[rand() % liveTargets.size()];
          // Hit Calculation Logic:
          // 1. Get evasion chance: Polymorphic call to the specific ship type's
          // evasion logic
          double chance = target->getEvasionChance(CANNON);

          // 2. Random Roll: Generate a number between 0 and 99
          int roll = rand() % 100;

          // 3. Determine Result: If roll is STRICTLY LESS than chance, it is a
          // hit
          bool hit = roll < chance;
          // get the crew member who operates this weapon (gunner may be empty
          // if the crew position is empty)
          Crew *cr = s->getGunner(i);
          // if the crew member exists, use their name; otherwise, use "unknown"
          string crewName = cr ? cr->getName() : "Unknown";

          dout << "    " << s->getTypeName() << " " << s->getName()
               << "'s Cannon crew " << crewName << " fires at "
               << target->getTypeName() << " " << target->getName() << "... ";
          // when hit
          if (hit) {
            int dmg = s->getCannonPower();
            target->receiveDamage(dmg);
            dout << "HIT! (" << dmg << " dmg)" << endl;
            // update live targets if this ship was destroyed
            if (target->isDestroyed()) {
              vector<Ship *> nextLive; // vector for ships still alive
              for (Ship *t : liveTargets)
                if (!t->isDestroyed())
                  nextLive.push_back(t); // replaced auto with Ship*
              liveTargets = nextLive;    // replace old list with updated list
            }
          } else {
            dout << "MISS." << endl;
          }
        }

        // Torpedoes attack (same logic with cannons)
        int torps = s->getActiveTorpedoes();
        for (int i = 0; i < torps; ++i) {
          if (liveTargets.empty())
            break;
          // random pick target
          Ship *target = liveTargets[rand() % liveTargets.size()];
          // Hit Calculation Logic (Torpedoes):
          // 1. Get evasion chance for TORPEDO (usually lower than Cannon)
          double chance = target->getEvasionChance(TORPEDO);

          // 2. Random Roll
          int roll = rand() % 100;

          // 3. Determine Result
          bool hit = roll < chance;
          // get the crew member who operates this weapon (gunner may be empty
          // if the crew position is empty)
          Crew *cr = s->getTorpHandler(i);
          // if the crew member exists, use their name; otherwise, use "Unknown"
          string crewName = cr ? cr->getName() : "Unknown";

          dout << "    " << s->getTypeName() << " " << s->getName()
               << "'s Torpedo crew " << crewName << " fires at "
               << target->getTypeName() << " " << target->getName() << "... ";
          // when hit
          if (hit) {
            int dmg = s->getTorpedoPower();
            target->receiveDamage(dmg);
            dout << "HIT! (" << dmg << " dmg)" << endl;
            // update live targets if this ship was destroyed
            if (target->isDestroyed()) {
              vector<Ship *> nextLive; // vector for ships still alive
              for (Ship *t : liveTargets)
                if (!t->isDestroyed())
                  nextLive.push_back(t); // replaced auto with Ship*
              liveTargets = nextLive;    // replace old list with updated list
            }
          } else {
            dout << "MISS." << endl;
          }
        }
      }
    }
    // main battle loop
    void runBattle() {
      int round = 1;
      while (true) {
        // check win conditions for each round
        int zapAlive = 0;
        for (Ship *s : zapShips)
          if (!s->isDestroyed())
            zapAlive++; // replaced auto with Ship*
        int rogAlive = 0;
        for (Ship *s : rogShips)
          if (!s->isDestroyed())
            rogAlive++; // replaced auto with Ship*
        // battle over if one side has no ships alive
        if (zapAlive == 0 || rogAlive == 0)
          break;

        dout << ">>> ROUND " << round << " <<<" << endl;

        // simultaneou phase:snapshot ships if alive at round start
        // the ships that still alive NOW(at start) can get to shoot, even if
        // killed this round
        vector<Ship *> activeZap;
        for (Ship *s : zapShips)
          if (!s->isDestroyed() && s->hasPilot())
            activeZap.push_back(s); // replaced auto with Ship*

        vector<Ship *> activeRog;
        for (Ship *s : rogShips)
          if (!s->isDestroyed() && s->hasPilot())
            activeRog.push_back(s); // replaced auto with Ship*

        /*execute shots
         note: shots will happen one-by-one in code, but logically they're
         simultaneous. key rule: ships that are alive at the START of a round
         get to shoot,even if they die during that same round. example: if Zap
         shoots and kills Rog, Rog still shoots back this turn because Rog was
         alive when the round started.
        */

        // who shooting first? Or Zap then Rog?
        //"both sides can shoot together" - as long as the logic holds, the
        // output
        // order is irrelevant.
        executeShots(activeZap, rogShips);
        executeShots(activeRog, zapShips);

        // status report
        // print round summary
        dout << endl << "--- Round Status Report ---" << endl;
        dout << "Zapezoids:" << endl;
        for (Ship *s : zapShips) { // replaced auto with Ship*
          dout << " [" << s->getID() << "] " << s->getTypeName() << " "
               << s->getName();
          if (s->isDestroyed())
            dout << " -- DESTROYED --" << endl;
          else
            dout << " (" << s->getHP() << "/" << s->getMaxHP() << ")" << endl;
        }
        dout << "Rogoatuskans:" << endl;
        for (Ship *s : rogShips) { // replaced auto with Ship*
          dout << " [" << s->getID() << "] " << s->getTypeName() << " "
               << s->getName();
          if (s->isDestroyed())
            dout << " -- DESTROYED --" << endl;
          else
            dout << " (" << s->getHP() << "/" << s->getMaxHP() << ")" << endl;
        }

        dout << endl;
        round++;
      }
      // declare winner
      dout << "========================================" << endl;
      dout << "               FINAL RESULT              " << endl;
      dout << "========================================" << endl;

      int zapAlive = 0;
      for (Ship *s : zapShips)
        if (!s->isDestroyed())
          zapAlive++; // replaced auto with Ship*
      if (zapAlive > 0)
        dout << "*** ZAPEZOIDS WIN! ***" << endl;
      else
        dout << "*** ROGOATUSKANS WIN! ***" << endl;
    }
    // entry point: load data and start to battle
    void start(string zShips, string zCrew, string rShips, string rCrew) {
      logFile.open("battle_log.txt");
      if (!logFile.is_open()) {
        cerr << "Warning: Could not open battle_log.txt for writing." << endl;
      }
      dout << "Loading data files..." << endl << endl;
      loadShips(zShips, ZAPEZOID);
      loadCrew(zCrew, ZAPEZOID);
      loadShips(rShips, ROGOATUSKAN);
      loadCrew(rCrew, ROGOATUSKAN);
      assignCrew();
      printFleetReport();
      runBattle();
    }
  };

  // ======================================================================================
  // MEMBER 4: DATA OFFICER (Main & Arguments)
  // ======================================================================================
<<<<<<< HEAD
  int main(int argc,
           char *argv[]) // main function (argc, argv) is the standard way to
                         // pass command line arguments to a C++ program
  {
    srand(time(0)); // seed the random number generator for random events like
                    // evasion and critical hits

    // Default file names (Hardcoded for debugging/IDE use) , change them to use
    // different ones
    string zShips = "zShips3.csv";
    string zCrew = "zCrew3.csv";
    string rShips = "rShips3.csv";
    string rCrew = "rCrew3.csv";
    == == ==
        = int main(
            int argc,
            char *argv[]) // argc: counts how many words user type in terminal,
                          // argv: actual list of those words (the file names)
    {
      srand(time(0)); // seed the random number generator for random events like
                      // evasion and critical hits

      // Default file names (Hardcoded for debugging/IDE use) , change them to
      // use different ones
      string zShips = "zShips3.csv";
      string zCrew = "zCrew3.csv";
      string rShips = "rShips3.csv";
      string rCrew = "rCrew3.csv";

      // Standard Command Line Argument Check using int argc and char* argv[] ,
      // the order in the terminal is zShips , zCrew , rShips , rCrew
      if (argc == 5) { // checks if user provide exactly 4 file names + program
                       // itself == 5
        zShips =
            argv[1]; // take those names provided from terminal and uses them
        zCrew = argv[2];
        rShips = argv[3];
        rCrew = argv[4];
      } else {
        cout << "No arguments provided (or incorrect number) use "
                "./ANGELFISHTT1L zShips.csv zCrew.csv rShips.csv rCrew.csv in "
                "the terminal"
             << endl;
        cout << "Using default hardcoded files: " << zShips << ", " << zCrew
             << ", " << rShips << ", " << rCrew << endl
             << endl;
      }

      Game game; // creates main game engine object
      game.start(zShips, zCrew, rShips, rCrew); // launch button 
>>>>>>> 933b7f9f5e970f827258162048c538d45977118b

      // Standard Command Line Argument Check using int argc and char* argv[] ,
      // the order in the terminal is zShips , zCrew , rShips , rCrew
      if (argc == 5) {
        zShips = argv[1];
        zCrew = argv[2];
        rShips = argv[3];
        rCrew = argv[4];
      } else {
        cout << "No arguments provided (or incorrect number) use "
                "./ANGELFISHTT1L "
                "zShips.csv zCrew.csv rShips.csv rCrew.csv in the terminal"
             << endl;
        cout << "Using default hardcoded files: " << zShips << ", " << zCrew
             << ", " << rShips << ", " << rCrew << endl
             << endl;
      }

      Game game;
      game.start(zShips, zCrew, rShips, rCrew);

      return 0;
    }

    // ======================================================================================
    // MEMBER 4: DATA OFFICER (String Helpers)
    // ======================================================================================
<<<<<<< HEAD
    // normalize: trim and lowercase for robust comparisons cause we had
    // processing errors need to add explaination
    string normalize(const string &s) {
      int first = s.find_first_not_of(" \t\r\n");
      if (first == string::npos)
        return "";
      int last = s.find_last_not_of(" \t\r\n");
      string out = s.substr(first, last - first + 1);
      transform(out.begin(), out.end(), out.begin(),
                [](unsigned char c) { return tolower(c); });
      return out;
    }
    == == == =
                 // normalize: trim and lowercase for robust comparisons cause
                 // we had processing errors need to add explaination
        string normalize(const string &s) {
      int first = s.find_first_not_of(
          " \t\r\n"); // looks for the first actual letter, skips spaces, tabs,
                      // or invisible newline characters
      if (first == string::npos)
        return ""; // returns empty result if string is totally empty
      int last =
          s.find_last_not_of(" \t\r\n"); // looks for very last actual letter
      string out = s.substr(
          first, last - first + 1); // cuts out word in the middle and throws
                                    // away extra spaces from the sides
      transform(out.begin(), out.end(), out.begin(), [](unsigned char c) {
        return tolower(c);
      }); // loops through every letter and forces it to become lowercase
      return out;
    }




>>>>>>> 933b7f9f5e970f827258162048c538d45977118b
