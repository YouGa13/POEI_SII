package employe_de_l_entreprise is

   SMIC : Float := 1_300.0;
   type VEHICULE is (Voiture, Moto, Trottinette, Velo, Transport_en_commun);
   type AVANTAGEVEHICULE is (Professionnelle, Personnelle);
   type FONCTION is (Patron, Commercial, RH, Employe);
   subtype SNOM is String (1 .. 10);

   type Date is record
      Jour  : Natural range 1 .. 31;
      Mois  : Natural range 1 .. 12;
      Annee : Natural range 1_900 .. 2_100;
   end record;

   type InfoEmploye (Fct : FONCTION := Employe) is record
      Nom              : SNOM;
      DateAnniversaire : Date;
      Salaire          : Float := SMIC;
      TypeVehicule     : VEHICULE;
      AvantageVoiture  : AVANTAGEVEHICULE;
      case Fct is
         when Patron | Commercial =>
            Frais      : Float;
            ForfaitTel : Boolean;
         when others =>
            TR : Float;
      end case;
   end record;

   type T_Info is array (Positive range <>) of InfoEmploye;

   procedure AfficheNom (Info : in out T_Info);

   procedure Augmentation
     (quidonc : in String; Pourcentage : in Float; InfoE : in out T_Info);

   function Augmentation
     (quidonc : in String; Pourcentage : in Float; InfoE : in T_Info)
      return T_Info;




private
   function copy_InfoE (InfoE : T_Info) return T_Info;

end employe_de_l_entreprise;
