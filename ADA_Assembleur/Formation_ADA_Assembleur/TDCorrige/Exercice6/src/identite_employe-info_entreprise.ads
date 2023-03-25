package identite_employe.info_entreprise is
   pragma Assertion_Policy (Check);

   SMIC : Float := 1_300.0;
   type VEHICULE is (Voiture, Moto, Trottinette, Velo, Transport_en_commun);
   type AVANTAGEVEHICULE is (Professionnelle, Personnelle);
   type FONCTION is (Patron, Commercial, RH, Employe);

   type InfoEmployeEntreprise is new InfoEmploye with record
      Salaire         : Float := SMIC;
      TypeVehicule    : VEHICULE;
      AvantageVoiture : AVANTAGEVEHICULE;
      Fct             : FONCTION;
   end record;

   type T_Info_Employe is array (Positive range <>) of InfoEmployeEntreprise;

   procedure Augmentation
     (quidoncNom  : in String; quidoncPrenom : in String;
      Pourcentage : in Float; InfoE : in out T_Info_Employe) with
      Pre => (Pourcentage > -1.0);

   procedure AfficheListe (Info : in out T_Info_Employe);

   procedure TriNom (Info : in out T_Info_Employe);

   function Augmentation
     (quidoncNom  : in String; quidoncPrenom : in String;
      Pourcentage : in Float; InfoE : in T_Info_Employe)
      return T_Info_Employe with
      Pre => (Pourcentage > -1.0);

   function copy_T_Info
     (Info : InfoEmployeEntreprise) return InfoEmployeEntreprise;

private

   function copy_InfoE (InfoE : T_Info_Employe) return T_Info_Employe;

end identite_employe.info_entreprise;
