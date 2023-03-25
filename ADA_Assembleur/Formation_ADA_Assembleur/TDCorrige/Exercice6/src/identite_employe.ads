with date_naissance; use date_naissance;
package identite_employe is

   subtype SNOM is String (1 .. 10);
   type InfoEmploye is tagged record
      Nom              : SNOM;
      Prenom           : SNOM;
      DateAnniversaire : Date;
   end record;

   type T_Info is array (Positive range <>) of InfoEmploye;

   procedure AfficheNom (Info : in InfoEmploye'Class);
   procedure AfficheListe (Info : in T_Info);
   procedure TriNom (Info : in out T_Info);

   function copy_T_Info (Info : InfoEmploye) return InfoEmploye;

end identite_employe;
