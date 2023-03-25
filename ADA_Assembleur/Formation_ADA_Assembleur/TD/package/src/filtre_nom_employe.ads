with employe_de_l_entreprise; use employe_de_l_entreprise;
package filtre_nom_employe is
 
   type T_Table is array (1 .. 100) of Integer;
   procedure Tri_salaire (Table : in out T_Info);
   procedure Tri_nom (Table : in out T_Info);
   procedure update_salaire (u_salaire : in out Float; Table : in out InfoEmploye );
   procedure afficher_salaire (Table : in out T_Info);
   procedure afficher_employe_tri_nom (Table : in out T_Info);
 
end filtre_nom_employe;
