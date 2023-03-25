with Ada.Text_IO;    use Ada.Text_IO;
with Ada.Exceptions; use Ada.Exceptions;
procedure Main is

   SMIC : Float := 1_300.0;
   type VEHICULE is (Voiture, Moto, Trottinette, Velo, Transport_en_commun);
   type AVANTAGEVEHICULE is (Professionnelle, Personnelle);
   type FONCTION is (Patron, Commercial, RH, Employe);
   subtype SNOM is String(1..10);
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

   procedure AfficheNom (Info : in out T_Info) is
      type T_Nom is array (Positive range Info'Range) of SNOM;
   begin
      for i in Info'Range loop
         Put_Line ("Nom de l'employé : " & Info (i).Nom);
         Put_Line ("Fonction de l'employé : " & Info (i).Fct'Image);
         Put_Line ("Salaire de l'employé : " & Info (i).Salaire'Image);
         New_Line;
      end loop;
   end AfficheNom;

   function copy_InfoE (InfoE : T_Info) return T_Info is
      Inforeturn : T_Info (InfoE'Range);
      Info1      : InfoEmploye;
   begin
      for i in InfoE'Range loop
         case InfoE (i).Fct is
            when Patron =>
               Info1 :=
                 (Patron, Nom      => InfoE (i).Nom,
                  DateAnniversaire =>
                    (InfoE (i).DateAnniversaire.Jour,
                     InfoE (i).DateAnniversaire.Mois,
                     InfoE (i).DateAnniversaire.Annee),
                  Salaire         => InfoE (i).Salaire,
                  TypeVehicule    => InfoE (i).TypeVehicule,
                  AvantageVoiture => InfoE (i).AvantageVoiture,
                  Frais           => InfoE (i).Frais,
                  ForfaitTel      => InfoE (i).ForfaitTel);
            when Commercial =>
               Info1 :=
                 (Commercial, Nom  => InfoE (i).Nom,
                  DateAnniversaire =>
                    (InfoE (i).DateAnniversaire.Jour,
                     InfoE (i).DateAnniversaire.Mois,
                     InfoE (i).DateAnniversaire.Annee),
                  Salaire         => InfoE (i).Salaire,
                  TypeVehicule    => InfoE (i).TypeVehicule,
                  AvantageVoiture => InfoE (i).AvantageVoiture,
                  Frais           => InfoE (i).Frais,
                  ForfaitTel      => InfoE (i).ForfaitTel);
            when RH =>
               Info1 :=
                 (RH, Nom          => InfoE (i).Nom,
                  DateAnniversaire =>
                    (InfoE (i).DateAnniversaire.Jour,
                     InfoE (i).DateAnniversaire.Mois,
                     InfoE (i).DateAnniversaire.Annee),
                  Salaire         => InfoE (i).Salaire,
                  TypeVehicule    => InfoE (i).TypeVehicule,
                  AvantageVoiture => InfoE (i).AvantageVoiture,
                  TR              => InfoE (i).TR);
            when Employe =>
               Info1 :=
                 (Employe, Nom     => InfoE (i).Nom,
                  DateAnniversaire =>
                    (InfoE (i).DateAnniversaire.Jour,
                     InfoE (i).DateAnniversaire.Mois,
                     InfoE (i).DateAnniversaire.Annee),
                  Salaire         => InfoE (i).Salaire,
                  TypeVehicule    => InfoE (i).TypeVehicule,
                  AvantageVoiture => InfoE (i).AvantageVoiture,
                  TR              => InfoE (i).TR);
            when others =>
               null;
         end case;
         Inforeturn (i) := Info1;
      end loop;
      return Inforeturn;
   end copy_InfoE;

   function Augmentation
     (quidonc : in String; Pourcentage : in Float; InfoE : in T_Info)
      return T_Info
   is
      SalaireNegatif : exception;
      newSalaire : Float := 0.0;
      Inforeturn : T_Info (InfoE'Range);
   begin
      Inforeturn := copy_InfoE (InfoE => InfoE);
      for i in Inforeturn'Range loop
         if (Inforeturn (i).Nom = quidonc) then
            newSalaire := InfoE (i).Salaire * (1.0 + Pourcentage);
            if newSalaire < 0.0 then
               raise SalaireNegatif;
            else
               Inforeturn (i).Salaire := newSalaire;
            end if;
         end if;
      end loop;
      return Inforeturn;
   exception
      when SalaireNegatif =>
         Put_Line ("Le salaire de " & quidonc & " est negatif : " & newSalaire'Image);
         return Inforeturn;
      when others =>
         Put_Line ("Autre probleme");
         return Inforeturn;
   end Augmentation;

   procedure Augmentation
     (quidonc : in String; Pourcentage : in Float; InfoE : in out T_Info)
   is
      SalaireNegatif : exception;
      newSalaire : Float := 0.0;
   begin
      for i in InfoE'Range loop
         if (InfoE (i).Nom = quidonc) then
            newSalaire := InfoE (i).Salaire * (1.0 + Pourcentage);
            if newSalaire < 0.0 then
               raise SalaireNegatif;
            else
               InfoE (i).Salaire := newSalaire;
            end if;
         end if;
      end loop;
   exception
      when SalaireNegatif =>
         Put_Line ("Le salaire de " & quidonc & " est negatif : " & newSalaire'Image);
      when others =>
         Put_Line ("Autre probleme");
   end Augmentation;

   InfoEntreprise : T_Info :=
     ((Nom             => "DUPOND    ", DateAnniversaire => (20, 10, 2_012),
       Salaire         => 2_000.0, TypeVehicule => Voiture,
       AvantageVoiture => Professionnelle, Fct => Commercial, Frais => 10.2,
       ForfaitTel      => True),
      (Nom             => "MARTIN    ", DateAnniversaire => (12, 06, 2_015),
       Salaire         => 2_150.0, TypeVehicule => Moto,
       AvantageVoiture => Personnelle, Fct => Employe, TR => 10.0),
      (Nom             => "BERNARD   ", DateAnniversaire => (12, 06, 1_975),
       Salaire         => SMIC, TypeVehicule => Trottinette,
       AvantageVoiture => Personnelle, Fct => RH, TR => 10.0),
      (Nom             => "JEAN      ", DateAnniversaire => (12, 06, 1_975),
       Salaire         => 4_005.0, TypeVehicule => Voiture,
       AvantageVoiture => Professionnelle, Fct => Patron, Frais => 10.2,
       ForfaitTel      => True));

begin
   AfficheNom (InfoEntreprise);
   InfoEntreprise :=
     Augmentation
       (InfoE       => InfoEntreprise, quidonc => "DUPOND    ",
        Pourcentage =>-1.10);
   AfficheNom (InfoEntreprise);
   Augmentation
     (InfoE => InfoEntreprise, quidonc => "BERNARD   ", Pourcentage => -1.025);
   AfficheNom (InfoEntreprise);
   Augmentation
     (InfoE => InfoEntreprise, quidonc => "JEAN      ", Pourcentage => 0.125);
   AfficheNom (InfoEntreprise);
end Main;
