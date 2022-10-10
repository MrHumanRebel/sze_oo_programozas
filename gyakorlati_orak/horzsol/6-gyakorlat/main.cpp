#include "Decl.hpp"

int main(void)
{
    dm_kiir nyzj('[', 2, 2), es('&', 3, 3), zzj(']', 4, 1) /*, alap*/; /* Objektumok példányosítása, beállítása */
    const dm_kiir alap;
    mind(nyzj, es, zzj, alap.getsK());
    es.getMutat()->setIsm(4).setSor(-1).setKar('@');
    // es.getIsm();
    mind(nyzj, es, zzj, alap.getsK());
    return 0;
}