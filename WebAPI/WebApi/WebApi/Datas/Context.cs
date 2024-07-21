using System;
using System.Collections.Generic;
using Microsoft.EntityFrameworkCore;
using WebApi.Models.DB;

namespace WebApi.Data;

public partial class Context : DbContext
{
    public Context()
    {
    }

    public Context(DbContextOptions<Context> options)
        : base(options)
    {
    }

    public virtual DbSet<BsyTblChampion> BsyTblChampions { get; set; }

    public virtual DbSet<BsyTblItem> BsyTblItems { get; set; }

    public virtual DbSet<BsyTblSkill> BsyTblSkills { get; set; }

    public virtual DbSet<BsyTblUser> BsyTblUsers { get; set; }

    public virtual DbSet<BsyTblUserItem> BsyTblUserItems { get; set; }

    public virtual DbSet<BsyTblUserSkill> BsyTblUserSkills { get; set; }

    public virtual DbSet<JjmTblChampion> JjmTblChampions { get; set; }

    public virtual DbSet<JjmTblItem> JjmTblItems { get; set; }

    public virtual DbSet<JjmTblSkill> JjmTblSkills { get; set; }

    public virtual DbSet<JjmTblUser> JjmTblUsers { get; set; }

    public virtual DbSet<JjmTblUserItem> JjmTblUserItems { get; set; }

    public virtual DbSet<JjmTblUserSkill> JjmTblUserSkills { get; set; }

    public virtual DbSet<JlTbLchampion> JlTbLchampions { get; set; }

    public virtual DbSet<JlTbLitem> JlTbLitems { get; set; }

    public virtual DbSet<JlTbLskill> JlTbLskills { get; set; }

    public virtual DbSet<JlTbLuser> JlTbLusers { get; set; }

    public virtual DbSet<JlTbLuseritem> JlTbLuseritems { get; set; }

    public virtual DbSet<JlTbLuserskill> JlTbLuserskills { get; set; }

    public virtual DbSet<LjTbLchampion> LjTbLchampions { get; set; }

    public virtual DbSet<PchTblChampion> PchTblChampions { get; set; }

    public virtual DbSet<PchTblItem> PchTblItems { get; set; }

    public virtual DbSet<PchTblSkill> PchTblSkills { get; set; }

    public virtual DbSet<PchTblUser> PchTblUsers { get; set; }

    public virtual DbSet<PchTblUserItem> PchTblUserItems { get; set; }

    public virtual DbSet<PchTblUserSkill> PchTblUserSkills { get; set; }

    public virtual DbSet<PsyTblChampion> PsyTblChampions { get; set; }

    public virtual DbSet<PsyTblItem> PsyTblItems { get; set; }

    public virtual DbSet<PsyTblSkill> PsyTblSkills { get; set; }

    public virtual DbSet<PsyTblUser> PsyTblUsers { get; set; }

    public virtual DbSet<PsyTblUserItem> PsyTblUserItems { get; set; }

    public virtual DbSet<PsyTblUserSkill> PsyTblUserSkills { get; set; }

    protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
#warning To protect potentially sensitive information in your connection string, you should move it out of source code. You can avoid scaffolding the connection string by using the Name= syntax to read it from configuration - see https://go.microsoft.com/fwlink/?linkid=2131148. For more guidance on storing connection strings, see http://go.microsoft.com/fwlink/?LinkId=723263.
        => optionsBuilder.UseMySql("server=121.190.138.117;port=3306;database=SBS_Study_20240701;user=PAStudy;password=PAtmxjel22..", Microsoft.EntityFrameworkCore.ServerVersion.Parse("10.3.32-mariadb"));

    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        modelBuilder
            .UseCollation("utf8_general_ci")
            .HasCharSet("utf8");

        modelBuilder.Entity<BsyTblChampion>(entity =>
        {
            entity.HasKey(e => e.Key).HasName("PRIMARY");

            entity.ToTable("BSY_TblChampion");

            entity.Property(e => e.Key)
                .HasColumnType("int(11)")
                .HasColumnName("_key");
            entity.Property(e => e.Name)
                .HasMaxLength(30)
                .HasColumnName("_name");
        });

        modelBuilder.Entity<BsyTblItem>(entity =>
        {
            entity.HasKey(e => e.Key).HasName("PRIMARY");

            entity.ToTable("BSY_TblItem");

            entity.Property(e => e.Key)
                .HasColumnType("int(11)")
                .HasColumnName("_key");
            entity.Property(e => e.Name)
                .HasMaxLength(30)
                .HasColumnName("_name");
        });

        modelBuilder.Entity<BsyTblSkill>(entity =>
        {
            entity.HasKey(e => e.Key).HasName("PRIMARY");

            entity.ToTable("BSY_TblSkill");

            entity.Property(e => e.Key)
                .HasColumnType("int(11)")
                .HasColumnName("_key");
            entity.Property(e => e.Name)
                .HasMaxLength(30)
                .HasColumnName("_name");
        });

        modelBuilder.Entity<BsyTblUser>(entity =>
        {
            entity.HasKey(e => e.Key).HasName("PRIMARY");

            entity.ToTable("BSY_TblUser");

            entity.HasIndex(e => e.ChampionKey, "_championKey");

            entity.Property(e => e.Key)
                .HasColumnType("int(11)")
                .HasColumnName("_key");
            entity.Property(e => e.ChampionKey)
                .HasColumnType("int(11)")
                .HasColumnName("_championKey");
            entity.Property(e => e.Level)
                .HasColumnType("int(11)")
                .HasColumnName("_level");

            entity.HasOne(d => d.ChampionKeyNavigation).WithMany(p => p.BsyTblUsers)
                .HasForeignKey(d => d.ChampionKey)
                .OnDelete(DeleteBehavior.Cascade)
                .HasConstraintName("BSY_TblUser_ibfk_1");
        });

        modelBuilder.Entity<BsyTblUserItem>(entity =>
        {
            entity.HasKey(e => e.Key).HasName("PRIMARY");

            entity.ToTable("BSY_TblUserItem");

            entity.HasIndex(e => e.ItemKey, "_itemKey");

            entity.HasIndex(e => e.UserKey, "_userKey");

            entity.Property(e => e.Key)
                .HasColumnType("int(11)")
                .HasColumnName("_key");
            entity.Property(e => e.ItemKey)
                .HasColumnType("int(11)")
                .HasColumnName("_itemKey");
            entity.Property(e => e.UserKey)
                .HasColumnType("int(11)")
                .HasColumnName("_userKey");

            entity.HasOne(d => d.ItemKeyNavigation).WithMany(p => p.BsyTblUserItems)
                .HasForeignKey(d => d.ItemKey)
                .OnDelete(DeleteBehavior.Cascade)
                .HasConstraintName("BSY_TblUserItem_ibfk_2");

            entity.HasOne(d => d.UserKeyNavigation).WithMany(p => p.BsyTblUserItems)
                .HasForeignKey(d => d.UserKey)
                .OnDelete(DeleteBehavior.Cascade)
                .HasConstraintName("BSY_TblUserItem_ibfk_1");
        });

        modelBuilder.Entity<BsyTblUserSkill>(entity =>
        {
            entity.HasKey(e => e.Key).HasName("PRIMARY");

            entity.ToTable("BSY_TblUserSkill");

            entity.HasIndex(e => e.SkillKey, "_skillKey");

            entity.HasIndex(e => e.UserKey, "_userKey");

            entity.Property(e => e.Key)
                .HasColumnType("int(11)")
                .HasColumnName("_key");
            entity.Property(e => e.SkillKey)
                .HasColumnType("int(11)")
                .HasColumnName("_skillKey");
            entity.Property(e => e.UserKey)
                .HasColumnType("int(11)")
                .HasColumnName("_userKey");

            entity.HasOne(d => d.SkillKeyNavigation).WithMany(p => p.BsyTblUserSkills)
                .HasForeignKey(d => d.SkillKey)
                .OnDelete(DeleteBehavior.Cascade)
                .HasConstraintName("BSY_TblUserSkill_ibfk_2");

            entity.HasOne(d => d.UserKeyNavigation).WithMany(p => p.BsyTblUserSkills)
                .HasForeignKey(d => d.UserKey)
                .OnDelete(DeleteBehavior.Cascade)
                .HasConstraintName("BSY_TblUserSkill_ibfk_1");
        });

        modelBuilder.Entity<JjmTblChampion>(entity =>
        {
            entity.HasKey(e => e.Key).HasName("PRIMARY");

            entity.ToTable("JJM_TblChampion");

            entity.Property(e => e.Key)
                .HasColumnType("int(11)")
                .HasColumnName("_key");
            entity.Property(e => e.Name)
                .HasMaxLength(30)
                .HasColumnName("_name");
        });

        modelBuilder.Entity<JjmTblItem>(entity =>
        {
            entity.HasKey(e => e.Key).HasName("PRIMARY");

            entity.ToTable("JJM_TblItem");

            entity.Property(e => e.Key)
                .HasColumnType("int(11)")
                .HasColumnName("_key");
            entity.Property(e => e.Name)
                .HasMaxLength(30)
                .HasColumnName("_name");
        });

        modelBuilder.Entity<JjmTblSkill>(entity =>
        {
            entity.HasKey(e => e.Key).HasName("PRIMARY");

            entity.ToTable("JJM_TblSkill");

            entity.Property(e => e.Key)
                .HasColumnType("int(11)")
                .HasColumnName("_key");
            entity.Property(e => e.Name)
                .HasMaxLength(30)
                .HasColumnName("_name");
        });

        modelBuilder.Entity<JjmTblUser>(entity =>
        {
            entity.HasKey(e => e.Key).HasName("PRIMARY");

            entity.ToTable("JJM_TblUser");

            entity.HasIndex(e => e.ChampionKey, "_championKey");

            entity.Property(e => e.Key)
                .HasColumnType("int(11)")
                .HasColumnName("_key");
            entity.Property(e => e.ChampionKey)
                .HasColumnType("int(11)")
                .HasColumnName("_championKey");
            entity.Property(e => e.Level)
                .HasColumnType("int(11)")
                .HasColumnName("_level");

            entity.HasOne(d => d.ChampionKeyNavigation).WithMany(p => p.JjmTblUsers)
                .HasForeignKey(d => d.ChampionKey)
                .OnDelete(DeleteBehavior.Cascade)
                .HasConstraintName("JJM_TblUser_ibfk_1");
        });

        modelBuilder.Entity<JjmTblUserItem>(entity =>
        {
            entity.HasKey(e => e.Key).HasName("PRIMARY");

            entity.ToTable("JJM_TblUserItem");

            entity.HasIndex(e => e.ItemKey, "_itemKey");

            entity.HasIndex(e => e.UserKey, "_userKey");

            entity.Property(e => e.Key)
                .HasColumnType("int(11)")
                .HasColumnName("_key");
            entity.Property(e => e.ItemKey)
                .HasColumnType("int(11)")
                .HasColumnName("_itemKey");
            entity.Property(e => e.UserKey)
                .HasColumnType("int(11)")
                .HasColumnName("_userKey");

            entity.HasOne(d => d.ItemKeyNavigation).WithMany(p => p.JjmTblUserItems)
                .HasForeignKey(d => d.ItemKey)
                .OnDelete(DeleteBehavior.Cascade)
                .HasConstraintName("JJM_TblUserItem_ibfk_2");

            entity.HasOne(d => d.UserKeyNavigation).WithMany(p => p.JjmTblUserItems)
                .HasForeignKey(d => d.UserKey)
                .OnDelete(DeleteBehavior.Cascade)
                .HasConstraintName("JJM_TblUserItem_ibfk_1");
        });

        modelBuilder.Entity<JjmTblUserSkill>(entity =>
        {
            entity.HasKey(e => e.Key).HasName("PRIMARY");

            entity.ToTable("JJM_TblUserSkill");

            entity.HasIndex(e => e.SkillKey, "_skillKey");

            entity.HasIndex(e => e.UserKey, "_userKey");

            entity.Property(e => e.Key)
                .HasColumnType("int(11)")
                .HasColumnName("_key");
            entity.Property(e => e.SkillKey)
                .HasColumnType("int(11)")
                .HasColumnName("_skillKey");
            entity.Property(e => e.UserKey)
                .HasColumnType("int(11)")
                .HasColumnName("_userKey");

            entity.HasOne(d => d.SkillKeyNavigation).WithMany(p => p.JjmTblUserSkills)
                .HasForeignKey(d => d.SkillKey)
                .OnDelete(DeleteBehavior.Cascade)
                .HasConstraintName("JJM_TblUserSkill_ibfk_2");

            entity.HasOne(d => d.UserKeyNavigation).WithMany(p => p.JjmTblUserSkills)
                .HasForeignKey(d => d.UserKey)
                .OnDelete(DeleteBehavior.Cascade)
                .HasConstraintName("JJM_TblUserSkill_ibfk_1");
        });

        modelBuilder.Entity<JlTbLchampion>(entity =>
        {
            entity
                .HasNoKey()
                .ToTable("JL_TbLChampion");

            entity.Property(e => e.Key)
                .HasColumnType("int(11)")
                .HasColumnName("_key");
            entity.Property(e => e.Name)
                .HasMaxLength(10)
                .HasColumnName("_name");
        });

        modelBuilder.Entity<JlTbLitem>(entity =>
        {
            entity
                .HasNoKey()
                .ToTable("JL_TbLitem");

            entity.Property(e => e.Key)
                .HasColumnType("int(11)")
                .HasColumnName("_key");
            entity.Property(e => e.Name)
                .HasMaxLength(30)
                .HasColumnName("_name");
        });

        modelBuilder.Entity<JlTbLskill>(entity =>
        {
            entity
                .HasNoKey()
                .ToTable("JL_TbLskill");

            entity.Property(e => e.Key)
                .HasColumnType("int(11)")
                .HasColumnName("_key");
            entity.Property(e => e.Name)
                .HasMaxLength(30)
                .HasColumnName("_name");
        });

        modelBuilder.Entity<JlTbLuser>(entity =>
        {
            entity
                .HasNoKey()
                .ToTable("JL_TbLuser");

            entity.Property(e => e.ChampionKey)
                .HasColumnType("int(11)")
                .HasColumnName("_championKey");
            entity.Property(e => e.Key)
                .HasColumnType("int(11)")
                .HasColumnName("_key");
            entity.Property(e => e.Level)
                .HasColumnType("int(11)")
                .HasColumnName("_level");
        });

        modelBuilder.Entity<JlTbLuseritem>(entity =>
        {
            entity
                .HasNoKey()
                .ToTable("JL_TbLuseritem");

            entity.Property(e => e.Key)
                .HasColumnType("int(11)")
                .HasColumnName("_key");
            entity.Property(e => e.Level)
                .HasColumnType("int(11)")
                .HasColumnName("_level");
            entity.Property(e => e.UserKey)
                .HasColumnType("int(11)")
                .HasColumnName("_userKey");
        });

        modelBuilder.Entity<JlTbLuserskill>(entity =>
        {
            entity
                .HasNoKey()
                .ToTable("JL_TbLuserskill");

            entity.Property(e => e.Key)
                .HasColumnType("int(11)")
                .HasColumnName("_key");
            entity.Property(e => e.Level)
                .HasColumnType("int(11)")
                .HasColumnName("_level");
            entity.Property(e => e.UserKey)
                .HasColumnType("int(11)")
                .HasColumnName("_userKey");
        });

        modelBuilder.Entity<LjTbLchampion>(entity =>
        {
            entity
                .HasNoKey()
                .ToTable("LJ_TbLChampion");

            entity.Property(e => e.Key)
                .HasColumnType("int(11)")
                .HasColumnName("_key");
            entity.Property(e => e.Name)
                .HasMaxLength(10)
                .HasColumnName("_name");
        });

        modelBuilder.Entity<PchTblChampion>(entity =>
        {
            entity.HasKey(e => e.Key).HasName("PRIMARY");

            entity.ToTable("PCH_TblChampion");

            entity.Property(e => e.Key)
                .HasColumnType("int(11)")
                .HasColumnName("_key");
            entity.Property(e => e.Name)
                .HasMaxLength(30)
                .HasColumnName("_name");
        });

        modelBuilder.Entity<PchTblItem>(entity =>
        {
            entity.HasKey(e => e.Key).HasName("PRIMARY");

            entity.ToTable("PCH_TblItem");

            entity.Property(e => e.Key)
                .HasColumnType("int(11)")
                .HasColumnName("_key");
            entity.Property(e => e.Name)
                .HasMaxLength(30)
                .HasColumnName("_name");
        });

        modelBuilder.Entity<PchTblSkill>(entity =>
        {
            entity.HasKey(e => e.Key).HasName("PRIMARY");

            entity.ToTable("PCH_TblSkill");

            entity.Property(e => e.Key)
                .HasColumnType("int(11)")
                .HasColumnName("_key");
            entity.Property(e => e.Name)
                .HasMaxLength(30)
                .HasColumnName("_name");
        });

        modelBuilder.Entity<PchTblUser>(entity =>
        {
            entity.HasKey(e => e.Key).HasName("PRIMARY");

            entity.ToTable("PCH_TblUser");

            entity.HasIndex(e => e.ChampionKey, "_championKey");

            entity.Property(e => e.Key)
                .HasColumnType("int(11)")
                .HasColumnName("_key");
            entity.Property(e => e.ChampionKey)
                .HasColumnType("int(11)")
                .HasColumnName("_championKey");
            entity.Property(e => e.Level)
                .HasColumnType("int(11)")
                .HasColumnName("_level");

            entity.HasOne(d => d.ChampionKeyNavigation).WithMany(p => p.PchTblUsers)
                .HasForeignKey(d => d.ChampionKey)
                .OnDelete(DeleteBehavior.Cascade)
                .HasConstraintName("PCH_TblUser_ibfk_1");
        });

        modelBuilder.Entity<PchTblUserItem>(entity =>
        {
            entity.HasKey(e => e.Key).HasName("PRIMARY");

            entity.ToTable("PCH_TblUserItem");

            entity.HasIndex(e => e.ItemKey, "_itemKey");

            entity.HasIndex(e => e.UserKey, "_userKey");

            entity.Property(e => e.Key)
                .HasColumnType("int(11)")
                .HasColumnName("_key");
            entity.Property(e => e.ItemKey)
                .HasColumnType("int(11)")
                .HasColumnName("_itemKey");
            entity.Property(e => e.UserKey)
                .HasColumnType("int(11)")
                .HasColumnName("_userKey");

            entity.HasOne(d => d.ItemKeyNavigation).WithMany(p => p.PchTblUserItems)
                .HasForeignKey(d => d.ItemKey)
                .OnDelete(DeleteBehavior.Cascade)
                .HasConstraintName("PCH_TblUserItem_ibfk_2");

            entity.HasOne(d => d.UserKeyNavigation).WithMany(p => p.PchTblUserItems)
                .HasForeignKey(d => d.UserKey)
                .OnDelete(DeleteBehavior.Cascade)
                .HasConstraintName("PCH_TblUserItem_ibfk_1");
        });

        modelBuilder.Entity<PchTblUserSkill>(entity =>
        {
            entity.HasKey(e => e.Key).HasName("PRIMARY");

            entity.ToTable("PCH_TblUserSkill");

            entity.HasIndex(e => e.SkillKey, "_skillKey");

            entity.HasIndex(e => e.UserKey, "_userKey");

            entity.Property(e => e.Key)
                .HasColumnType("int(11)")
                .HasColumnName("_key");
            entity.Property(e => e.SkillKey)
                .HasColumnType("int(11)")
                .HasColumnName("_skillKey");
            entity.Property(e => e.UserKey)
                .HasColumnType("int(11)")
                .HasColumnName("_userKey");

            entity.HasOne(d => d.SkillKeyNavigation).WithMany(p => p.PchTblUserSkills)
                .HasForeignKey(d => d.SkillKey)
                .OnDelete(DeleteBehavior.Cascade)
                .HasConstraintName("PCH_TblUserSkill_ibfk_2");

            entity.HasOne(d => d.UserKeyNavigation).WithMany(p => p.PchTblUserSkills)
                .HasForeignKey(d => d.UserKey)
                .OnDelete(DeleteBehavior.Cascade)
                .HasConstraintName("PCH_TblUserSkill_ibfk_1");
        });

        modelBuilder.Entity<PsyTblChampion>(entity =>
        {
            entity.HasKey(e => e.Key).HasName("PRIMARY");

            entity.ToTable("PSY_TblChampion");

            entity.Property(e => e.Key)
                .HasColumnType("int(11)")
                .HasColumnName("_key");
            entity.Property(e => e.Name)
                .HasMaxLength(30)
                .HasColumnName("_name");
        });

        modelBuilder.Entity<PsyTblItem>(entity =>
        {
            entity.HasKey(e => e.Key).HasName("PRIMARY");

            entity.ToTable("PSY_TblItem");

            entity.Property(e => e.Key)
                .ValueGeneratedNever()
                .HasColumnType("int(11)")
                .HasColumnName("_key");
            entity.Property(e => e.Name)
                .HasMaxLength(30)
                .HasColumnName("_name");
        });

        modelBuilder.Entity<PsyTblSkill>(entity =>
        {
            entity.HasKey(e => e.Key).HasName("PRIMARY");

            entity.ToTable("PSY_TblSkill");

            entity.Property(e => e.Key)
                .ValueGeneratedNever()
                .HasColumnType("int(11)")
                .HasColumnName("_key");
            entity.Property(e => e.Name)
                .HasMaxLength(30)
                .HasColumnName("_name");
        });

        modelBuilder.Entity<PsyTblUser>(entity =>
        {
            entity.HasKey(e => e.Key).HasName("PRIMARY");

            entity.ToTable("PSY_TblUser");

            entity.HasIndex(e => e.ChampionKey, "_championKey");

            entity.Property(e => e.Key)
                .ValueGeneratedNever()
                .HasColumnType("int(11)")
                .HasColumnName("_key");
            entity.Property(e => e.ChampionKey)
                .HasColumnType("int(11)")
                .HasColumnName("_championKey");
            entity.Property(e => e.Level)
                .HasColumnType("int(11)")
                .HasColumnName("_level");

            entity.HasOne(d => d.ChampionKeyNavigation).WithMany(p => p.PsyTblUsers)
                .HasForeignKey(d => d.ChampionKey)
                .OnDelete(DeleteBehavior.Cascade)
                .HasConstraintName("PSY_TblUser_ibfk_1");
        });

        modelBuilder.Entity<PsyTblUserItem>(entity =>
        {
            entity.HasKey(e => e.Key).HasName("PRIMARY");

            entity.ToTable("PSY_TblUserItem");

            entity.HasIndex(e => e.ItemKey, "_itemKey");

            entity.HasIndex(e => e.UserKey, "_userKey");

            entity.Property(e => e.Key)
                .ValueGeneratedNever()
                .HasColumnType("int(11)")
                .HasColumnName("_key");
            entity.Property(e => e.ItemKey)
                .HasColumnType("int(11)")
                .HasColumnName("_itemKey");
            entity.Property(e => e.UserKey)
                .HasColumnType("int(11)")
                .HasColumnName("_userKey");

            entity.HasOne(d => d.ItemKeyNavigation).WithMany(p => p.PsyTblUserItems)
                .HasForeignKey(d => d.ItemKey)
                .OnDelete(DeleteBehavior.Cascade)
                .HasConstraintName("PSY_TblUserItem_ibfk_2");

            entity.HasOne(d => d.UserKeyNavigation).WithMany(p => p.PsyTblUserItems)
                .HasForeignKey(d => d.UserKey)
                .OnDelete(DeleteBehavior.Cascade)
                .HasConstraintName("PSY_TblUserItem_ibfk_1");
        });

        modelBuilder.Entity<PsyTblUserSkill>(entity =>
        {
            entity.HasKey(e => e.Key).HasName("PRIMARY");

            entity.ToTable("PSY_TblUserSKill");

            entity.HasIndex(e => e.SkillKey, "_skillKey");

            entity.HasIndex(e => e.UserKey, "_userKey");

            entity.Property(e => e.Key)
                .ValueGeneratedNever()
                .HasColumnType("int(11)")
                .HasColumnName("_key");
            entity.Property(e => e.SkillKey)
                .HasColumnType("int(11)")
                .HasColumnName("_skillKey");
            entity.Property(e => e.UserKey)
                .HasColumnType("int(11)")
                .HasColumnName("_userKey");

            entity.HasOne(d => d.SkillKeyNavigation).WithMany(p => p.PsyTblUserSkills)
                .HasForeignKey(d => d.SkillKey)
                .OnDelete(DeleteBehavior.Cascade)
                .HasConstraintName("PSY_TblUserSKill_ibfk_2");

            entity.HasOne(d => d.UserKeyNavigation).WithMany(p => p.PsyTblUserSkills)
                .HasForeignKey(d => d.UserKey)
                .OnDelete(DeleteBehavior.Cascade)
                .HasConstraintName("PSY_TblUserSKill_ibfk_1");
        });

        OnModelCreatingPartial(modelBuilder);
    }

    partial void OnModelCreatingPartial(ModelBuilder modelBuilder);
}
