procedure Main is
   SMIC : Float := 1_300.0;
   type VEHICULE is (Voiture, Moto, Trottinette, Velo, Transport_en_commun);
   type AVANTAGEVEHICULE is (Professionnelle, Personnelle);
   type FONCTION is (Patron, Commerciale, RH, Employe);
   type Date is record
      Jour  : Natural range 1 .. 31;
      Mois  : Natural range 1 .. 12;
      Annee : Natural range 1_900 .. 2_100;
   end record;

   type InfoEmploye (Fct : FONCTION := Employe) is record

      Nom              : String (1 .. 50);
      DateAnniversaire : Date;
      Salaire          : Float := SMIC;
      TypeVehicule     : VEHICULE;
      AvantageVoiture  : AVANTAGEVEHICULE;
      case Fct is
         when Patron | Commerciale =>
            Frais      : Float;
            ForfaitTel : Boolean;
         when others =>
            TR : Float;

      end case;
      --  Fonct         : FONCTION := Fct;
   end record;
   jean : InfoEmploye (Employe);
begin
   --  Insert code here.
   --  J.fct:=Employe;
   jean.TR  := 10.0;
   --  J.Frais := 20.3;
   null;
end Main;
