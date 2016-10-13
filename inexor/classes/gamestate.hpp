#pragma once

#include "inexor/templates/projectilestate.hpp"
#include "inexor/deprecated/fixed_geom.hpp"
#include "inexor/classes/fpsstate.hpp"
#include "inexor/enumerations/enum_client_states.hpp"

namespace inexor {
namespace server {

    /// 
    extern const int DEATHMILLIS;
    
    struct fpsstate;

    /// 
    struct gamestate : fpsstate
    {
        vec o;
        int state, editstate;
        int lastdeath, deadflush, lastspawn, lifesequence;
        int lastshot;
        projectilestate<8> rockets, grenades, bombs;
        int frags, flags, deaths, teamkills, 
            shotdamage, //all damage your shots could have made
            damage, tokens;
        int lasttimeplayed, timeplayed;
        float effectiveness;

        gamestate();

        bool isalive(int gamemillis);

        bool waitexpired(int gamemillis);

        void reset();

        void respawn();

        void reassign();

        void setbackupweapon(int weapon);

    };

};
};