with mere; use mere;
package Mere.fille is
   
   SMIC : Float := 1_300.0;
   
   type VEHICULE is (Voiture, Moto, Trottinette, Velo, Transport_en_commun);
   
   type InfoEmploye (Fct : FONCTION := Employe) is record
      
      Salaire          : Float := SMIC;
      TypeVehicule     : VEHICULE;
      
   end record;
   
   type T_Info is array (Positive range <>) of InfoEmploye;
   
   procedure Set_salary( salaire : in out Float) ;
   procedure Tri_nom (Table : in out T_Info);
   
   
end Mere.fille ;
