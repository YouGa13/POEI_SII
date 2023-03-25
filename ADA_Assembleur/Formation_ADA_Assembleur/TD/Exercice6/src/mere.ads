package Mere is
   
   subtype SNOM is String (1 .. 10);

   type Date is record
      Jour  : Natural range 1 .. 31;
      Mois  : Natural range 1 .. 12;
      Annee : Natural range 1_900 .. 2_100;
   end record;

   type InfoEmploye  is record
      Nom              : SNOM;
      Prenom           : SNOM;
      DateAnniversaire : Date;
   end record;
   
   type T_Info is array (Positive range <>) of InfoEmploye;
   
   procedure Afficher_nom(Info : in out T_Info) ; 
  
end Mere ;
