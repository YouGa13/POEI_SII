with Ada.Text_IO; use Ada.Text_IO;
package body identite_employe.info_entreprise is

   procedure AfficheListe (Info : in out T_Info_Employe) is
      type T_Nom is array (Positive range Info'Range) of SNOM;
   begin
      Put_Line
        ("####################################################################");
      for i in Info'Range loop
         AfficheNom (Info (i));
         Put_Line ("Fonction          : " & Info (i).Fct'Image);
         Put_Line ("Salaire           : " & Info (i).Salaire'Image);
         Put_Line ("------------------------------------------");
      end loop;
      Put_Line
        ("####################################################################");
      New_Line;
   end AfficheListe;

   function Augmentation
     (quidoncNom  : in String; quidoncPrenom : in String;
      Pourcentage : in Float; InfoE : in T_Info_Employe) return T_Info_Employe
   is
      SalaireSuperieur : exception;
      newSalaire    : Float := 0.0;
      Inforeturn    : T_Info_Employe (InfoE'Range);
      SalairePatron : Float := 0.0;
   begin
      for i in InfoE'Range loop
         if InfoE (i).Fct = Patron then
            SalairePatron := InfoE (i).Salaire;
         end if;

      end loop;
      Inforeturn := copy_InfoE (InfoE => InfoE);
      for i in Inforeturn'Range loop
         if (Inforeturn (i).Nom = quidoncNom) then
            newSalaire := InfoE (i).Salaire * (1.0 + Pourcentage);
            if newSalaire > SalairePatron and InfoE (i).Fct /= Patron then
               raise SalaireSuperieur;
            else
               Inforeturn (i).Salaire := newSalaire;
            end if;
         end if;
      end loop;
      return Inforeturn;
   exception
      when SalaireSuperieur =>
         Put_Line
           ("Le salaire de " & quidoncNom & " " & quidoncPrenom &
            " est supérieur au patron !!!! " & newSalaire'Image & " > " &
            SalairePatron'Image);
         return Inforeturn;
      when others =>
         Put_Line ("Autre probleme");
         return Inforeturn;
   end Augmentation;

   procedure Augmentation
     (quidoncNom  : in String; quidoncPrenom : in String;
      Pourcentage : in Float; InfoE : in out T_Info_Employe)
   is
      SalaireSuperieur : exception;
      newSalaire    : Float := 0.0;
      SalairePatron : Float := 0.0;
   begin
      for i in InfoE'Range loop
         if InfoE (i).Fct = Patron then
            SalairePatron := InfoE (i).Salaire;
         end if;
      end loop;
      for i in InfoE'Range loop
         if (InfoE (i).Nom = quidoncNom and InfoE (i).Prenom = quidoncPrenom)
         then
            newSalaire := InfoE (i).Salaire * (1.0 + Pourcentage);
            if newSalaire > SalairePatron and InfoE (i).Fct /= Patron then
               raise SalaireSuperieur;
            else
               InfoE (i).Salaire := newSalaire;
            end if;
         end if;
      end loop;
   exception
      when SalaireSuperieur =>
         Put_Line
           ("Le salaire de " & quidoncNom & " " & quidoncPrenom &
            " est supérieur au patron !!!! " & newSalaire'Image & " > " &
            SalairePatron'Image);
      when others =>
         Put_Line ("Autre probleme");
   end Augmentation;

   function copy_InfoE (InfoE : T_Info_Employe) return T_Info_Employe is
      Inforeturn : T_Info_Employe (InfoE'Range);
      Info1      : InfoEmployeEntreprise;
   begin
      for i in InfoE'Range loop
         Info1 :=
           (Nom              => InfoE (i).Nom, Prenom => InfoE (i).Prenom,
            DateAnniversaire =>
              (InfoE (i).DateAnniversaire.Jour,
               InfoE (i).DateAnniversaire.Mois,
               InfoE (i).DateAnniversaire.Annee),
            Salaire         => InfoE (i).Salaire,
            TypeVehicule    => InfoE (i).TypeVehicule,
            AvantageVoiture => InfoE (i).AvantageVoiture,
            Fct             => InfoE (i).Fct);
         Inforeturn (i) := Info1;
      end loop;
      return Inforeturn;
   end copy_InfoE;

   function copy_T_Info
     (Info : InfoEmployeEntreprise) return InfoEmployeEntreprise
   is
   begin
      return
        (Nom              => Info.Nom, Prenom => Info.Prenom,
         DateAnniversaire =>
           (Info.DateAnniversaire.Jour, Info.DateAnniversaire.Mois,
            Info.DateAnniversaire.Annee),
         Salaire         => Info.Salaire, TypeVehicule => Info.TypeVehicule,
         AvantageVoiture => Info.AvantageVoiture, Fct => Info.Fct);
   end copy_T_Info;

   procedure TriNom (Info : in out T_Info_Employe) is
      Tri1N   : SNOM;
      Tri2N   : SNOM;
      InfoTmp : T_Info_Employe (Info'Range);
      index   : Integer := Info'Length;
   begin
      for i in Info'Range loop
         Tri1N := Info (i).Nom;
         for j in Info'Range loop
            Tri2N := Info (j).Nom;
            if Tri1N < Tri2N then
               index := index - 1;
            end if;
         end loop;
         InfoTmp (index) := copy_T_Info (Info => Info (i));
         index           := Info'Length;
      end loop;
      Info := copy_InfoE (InfoE => InfoTmp);

   end TriNom;

end identite_employe.info_entreprise;
