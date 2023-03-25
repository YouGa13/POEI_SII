with Ada.Text_IO;             use Ada.Text_IO;
with Ada.Exceptions;          use Ada.Exceptions;
with employe_de_l_entreprise; use employe_de_l_entreprise;
procedure Main is

   InfoEntreprise : T_Info :=
     ((Commercial, Nom => "DUPOND    ", DateAnniversaire => (20, 10, 2_012),
       Salaire         => 2_000.0, TypeVehicule => Voiture,
       AvantageVoiture => Professionnelle, Frais => 10.2, ForfaitTel => True),
      (Employe, Nom    => "MARTIN    ", DateAnniversaire => (12, 06, 2_015),
       Salaire         => 2_150.0, TypeVehicule => Moto,
       AvantageVoiture => Personnelle, TR => 10.0),
      (RH, Nom         => "BERNARD   ", DateAnniversaire => (12, 06, 1_975),
       Salaire         => SMIC, TypeVehicule => Trottinette,
       AvantageVoiture => Personnelle, TR => 10.0),
      (Patron, Nom     => "JEAN      ", DateAnniversaire => (12, 06, 1_975),
       Salaire         => 4_005.0, TypeVehicule => Voiture,
       AvantageVoiture => Professionnelle, Frais => 10.2, ForfaitTel => True));

begin
   AfficheNom (InfoEntreprise);
   InfoEntreprise :=
     Augmentation
       (InfoE       => InfoEntreprise, quidonc => "DUPOND    ",
        Pourcentage => -1.10);
   Augmentation
     (InfoE => InfoEntreprise, quidonc => "BERNARD   ", Pourcentage => -1.025);
   Augmentation
     (InfoE => InfoEntreprise, quidonc => "JEAN      ", Pourcentage => 0.125);
   AfficheNom (InfoEntreprise);
end Main;
